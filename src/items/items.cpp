module items;

import exceptions;
import std.core;
import std.filesystem;

import :default_items;

namespace items {
	void setUp() {
		try {
			// Open file for reading
			std::ifstream file("data/items.json");
			Json::Reader reader;
			Json::Value json_value;

			// Read file into json_value
			if (!reader.parse(file, json_value)) {
				throw BadJsonException("Unable to parse items.json");
			}

			// Set members to values from json
			fromJson(json_value);
		} catch (const std::exception&) {
			// Reset members to default values
			default_items::setUp();

			// TODO: alert that creating items from json was unsuccessful with message e.what()
		}
	}

	void reset() noexcept {
		// Delete each item in items
		for (const auto& [item_name, item] : items) {
			delete item;
		}

		// Erase all elements in items
		items.clear();
	}

	void fromJson(const Json::Value& json_value) {
		try {
			reset();

			for (const std::string& item_name : json_value.getMemberNames()) {
				Json::Value item_json_value = json_value[item_name];
				std::string item_type = item_json_value["item_type"].asString();

				if (item_type == "Block") {
					addItem(new Block(item_json_value));
				} else if (item_type == "Cloth") {
					addItem(new Cloth(item_json_value));
				} else if (item_type == "Ingot") {
					addItem(new Ingot(item_json_value));
				} else if (item_type == "Leather") {
					addItem(new Leather(item_json_value));
				} else if (item_type == "Plank") {
					addItem(new Plank(item_json_value));
				} else if (item_type == "RawResource") {
					addItem(new RawResource(item_json_value));
				} else if (item_type == "RefiningComponent") {
					addItem(new RefiningComponent(item_json_value));
				} else if (item_type == "RefiningGear") {
					addItem(new RefiningGear(item_json_value));
				} else {
					throw BadValueException("Unrecognized item_type \"" + item_type + "\" in items");
				}
			}

			update(itemUpdateOrder());
		} catch (const std::exception& e) {
			throw BadJsonException("items is malformed", e);
		}
	}

	Json::Value toJson() {
		Json::Value json_value;

		for (const auto& [item_name, item] : items) {
			json_value[item_name] = item->toJson();
		}

		return json_value;
	}

	void writeToDisk() {
		// Create data directory if missing
		std::filesystem::create_directory("data");

		// Create items.json file
		std::ofstream file("data/items.json");

		// Write json into file
		Json::StyledWriter styled_writer;
		file << styled_writer.write(toJson());
	}

	void addItem(Item* item) {
		if (!items.insert({ item->getItemName(), item }).second) {
			throw BadValueException("Unable to add duplicate item \"" + item->getItemName());
		}
	}

	void update(RefinedResource* refined_resource) {
		bestInstantCraft(refined_resource);
		bestCraft(refined_resource);
	}

	void update(const std::list<Item*>& item_update_order) {
		for (const auto& item : item_update_order) {
			if (RefinedResource* refined_resource = dynamic_cast<RefinedResource*>(item); refined_resource) {
				update(refined_resource);
			} // else if dynamic cast to another item if and overload update with other item
		}
	}

	void setBuyEqualsSell(Item* item, const bool buy_equals_sell) {
		// Only a Resource has buy_equals_sell
		Resource* resource = dynamic_cast<Resource*>(item);

		// Return early if item cannot dynamic cast to a Resource
		if (!resource) {
			return;
		}

		// Set buy_equals_sell then update if necessary
		if (resource->setBuyEqualsSell(buy_equals_sell)) {
			update(resource->getItemUpdateOrder());
		}
	}

	void setSellPrice(Item* item, const double sell_price) {
		// Only a Resource has sell_price
		Resource* resource = dynamic_cast<Resource*>(item);

		// Return early if item cannot dynamic cast to a Resource
		if (!resource) {
			return;
		}

		// Set sell_price then update if necessary
		if (resource->setSellPrice(sell_price)) {
			update(resource->getItemUpdateOrder());
		}
	}

	void setBuyPrice(Item* item, const double buy_price) {
		// Only a Resource has buy_price
		Resource* resource = dynamic_cast<Resource*>(item);

		// Return early if item cannot dynamic cast to a Resource
		if (!resource) {
			return;
		}

		// Set buy_price then update if necessary
		if (resource->setBuyPrice(buy_price)) {
			update(resource->getItemUpdateOrder());
		}
	}

	std::list<Item*> itemUpdateOrder() {
		// Item node
		struct ItemNode {
			std::unordered_set<Item*> parent_items;
			std::unordered_set<Item*> child_items;
			std::unordered_set<Item*> item_update_order_items;
			std::list<Item*> item_update_order;
			bool completed = false;

			ItemNode() = default;

			explicit ItemNode(Item* item) {
				// Only a RefinedResource has parents
				RefinedResource* refined_resource = dynamic_cast<RefinedResource*>(item);

				// Return early if item cannot dynamic cast to a RefinedResource
				if (!refined_resource) {
					return;
				}

				// Ingredients found in recipes are parents
				for (auto [cit, cend] = recipe_book::recipeRange(refined_resource->getItemName()); cit != cend; ++cit) {
					for (const auto& [ingredient_name, amount] : cit->second.getIngredients()) {
						parent_items.insert(getItem<Item>(ingredient_name));
					}
				}
			}
		};

		// Item graph
		std::unordered_map<Item*, ItemNode> item_graph;

		// Create master item and node
		class MasterItem final : public Item {
			public:
				MasterItem() : Item(std::string("Master Item")) {};
		} master_item;
		ItemNode master_node;

		// Populate item graph and add every item as child of master node
		for (const auto& [item_name, item] : items) {
			item_graph.insert({ item, ItemNode(item) });
			master_node.child_items.insert(item);
		}

		// Insert master node into item graph
		item_graph.insert({ &master_item, std::move(master_node) });

		// Store unordered set of all children for each item
		for (const auto& [item, item_node] : item_graph) {
			for (const auto& parent : item_node.parent_items) {
				item_graph.at(parent).child_items.insert(item);
			}
		}

		// Recursive lambda function for finding item update order
		std::function<std::list<Item*>(Item*)> find_item_update_order = [&](Item* item) {
			// Get item node for this item
			auto& [parent_items, child_items, item_update_order_items, item_update_order, completed] = item_graph.at(item);

			// Return early if item already completed
			if (completed) {
				return item_update_order;
			}

			// Build item update order from item update order of children
			if (!child_items.empty()) {
				// Take item update order from first child as a starting point
				auto it = child_items.begin();
				item_update_order = find_item_update_order(*it);
				item_update_order_items = item_graph.at(*it).item_update_order_items;
				++it;

				// Build item update order from the rest of the children
				for (; it != child_items.end(); ++it) {
					auto child_item_update_order = find_item_update_order(*it);

					// Find first item in child item update order that is already in item update order items
					auto it = child_item_update_order.begin();
					for (; it != child_item_update_order.end(); ++it) {
						if (!item_update_order_items.insert(*it).second) {
							break;
						}
					}

					// Add all items before this item to beginning of item update order
					item_update_order.splice(item_update_order.begin(), child_item_update_order, child_item_update_order.begin(), it);
				}
			}

			// Add itself to item update order before setting as completed
			item_update_order_items.insert(item);
			item_update_order.push_front(item);
			completed = true;

			// Return item update order
			return item_update_order;
		};

		// Save item update order for each item
		for (const auto& [item, item_node] : item_graph) {
			item->setItemUpdateOrder(find_item_update_order(item));
		}

		// Save return value
		item_graph.at(&master_item).item_update_order.pop_front();
		std::list<Item*> master_item_update_order = item_graph.at(&master_item).item_update_order;

		// Return master item update order
		return master_item_update_order;
	}

	void bestInstantCraft(RefinedResource* refined_resource) {
		double best_instant_craft_cost = HUGE_VAL;
		recipe_book::Recipe best_instant_recipe(refined_resource->getItemName());

		for (auto [cit, cend] = recipe_book::recipeRange(refined_resource->getItemName()); cit != cend; ++cit) {
			// Get Recipe
			recipe_book::Recipe recipe = cit->second;

			// Calculate the total cost of the ingredients in the recipe
			double recipe_cost = 0.;
			for (const auto& [ingredient_name, amount] : recipe.getIngredients()) {
				recipe_cost += amount * getItem<Resource>(ingredient_name)->bestInstantAcquireCost();
			}

			// Calculate the instant craft cost of the recipe
			const double instant_craft_cost = (recipe_cost + refined_resource->craftTax()) / refined_resource->yield();

			// Update best instant craft if current instant craft is better
			if (instant_craft_cost < best_instant_craft_cost) {
				best_instant_craft_cost = instant_craft_cost;
				best_instant_recipe = recipe;
			}
		}

		// Save the best instant craft cost and recipe
		refined_resource->setBestInstantCraftCost(best_instant_craft_cost);
		refined_resource->setBestInstantRecipe(best_instant_recipe);
	}

	void bestCraft(RefinedResource* refined_resource) {
		double best_craft_cost = HUGE_VAL;
		recipe_book::Recipe best_recipe(refined_resource->getItemName());

		for (auto [cit, cend] = recipe_book::recipeRange(refined_resource->getItemName()); cit != cend; ++cit) {
			// Get Recipe
			recipe_book::Recipe recipe = cit->second;

			// Calculate the total cost of the ingredients in the recipe
			double recipe_cost = 0.;
			for (const auto& [ingredient_name, amount] : recipe.getIngredients()) {
				recipe_cost += amount * getItem<Resource>(ingredient_name)->bestAcquireCost();
			}

			// Calculate the craft cost of the recipe
			const double craft_cost = (recipe_cost + refined_resource->craftTax()) / refined_resource->yield();

			// Update the best craft is current craft is better
			if (craft_cost < best_craft_cost) {
				best_craft_cost = craft_cost;
				best_recipe = recipe;
			}
		}

		// Save the best craft cost and recipe
		refined_resource->setBestCraftCost(best_craft_cost);
		refined_resource->setBestRecipe(best_recipe);
	}
}
