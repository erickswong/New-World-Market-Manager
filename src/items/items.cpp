module items;

import exceptions;
import std.core;
import std.filesystem;

import :default_items;
import :block;
import :cloth;
import :gear;
import :ingot;
import :leather;
import :plank;
import :raw_resource;
import :refining_component;

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
	}

	void fromJson(Json::Value json_value) {
		try {
			reset();

			for (const std::string& item_name : json_value.getMemberNames()) {
				Json::Value item_json_value = json_value[item_name];
				std::string item_type = item_json_value["item_type"].asString();

				if (item_type == "Block") {
					insert(item_name, new Block(item_json_value));
				} else if (item_type == "Cloth") {
					insert(item_name, new Cloth(item_json_value));
				} else if (item_type == "Gear") {
					insert(item_name, new Gear(item_json_value));
				} else if (item_type == "Ingot") {
					insert(item_name, new Ingot(item_json_value));
				} else if (item_type == "Leather") {
					insert(item_name, new Leather(item_json_value));
				} else if (item_type == "Plank") {
					insert(item_name, new Plank(item_json_value));
				} else if (item_type == "RawResource") {
					insert(item_name, new RawResource(item_json_value));
				} else if (item_type == "RefiningComponent") {
					insert(item_name, new RefiningComponent(item_json_value));
				} else {
					throw BadValueException("Unrecognized item_type \"" + item_type + "\" in items");
				}
			}

			analyze(itemUpdateOrder());
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

		// Create settings.json file
		std::ofstream file("data/items.json");

		// Write json into file
		Json::StyledWriter styled_writer;
		file << styled_writer.write(toJson());
	}

	Item* at(const std::string& item_name) {
		return items.at(item_name);
	}

	void insert(const std::string& item_name, Item* item) {
		items.insert({ item_name, item });
	}

	void analyze(Item* item) {
		try {
			auto& [best_instant_craft_cost, best_craft_cost, best_instant_profit_margin, best_profit_margin, best_instant_recipe, best_recipe] = item->getAnalysis();
			const auto sell_price = item->getSellPrice();

			std::tie(best_instant_recipe, best_instant_craft_cost) = getBestInstantCraft(item);
			std::tie(best_recipe, best_craft_cost) = getBestCraft(item);

			best_instant_profit_margin = profitMargin(sell_price, best_instant_craft_cost);
			best_profit_margin = profitMargin(sell_price, best_craft_cost);
		} catch (NotUsedException&) {
			// Item does not use analysis
		}
	}

	void analyze(const std::list<Item*>& item_update_order) {
		for (const auto& item : item_update_order) {
			analyze(item);
		}
	}

	void setBuyEqualsSell(Item* item, const bool buy_equals_sell) {
		if (item->setBuyEqualsSell(buy_equals_sell)) {
			analyze(item->getItemUpdateOrder());
		}
	}

	void setSellPrice(Item* item, const double sell_price) {
		if (item->setSellPrice(sell_price)) {
			analyze(item->getItemUpdateOrder());
		}
	}

	void setBuyPrice(Item* item, const double buy_price) {
		if (item->setBuyPrice(buy_price)) {
			analyze(item->getItemUpdateOrder());
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
				// Store unordered set of all parents for this item
				try {
					// Ingredients found in recipes are parents
					for (auto& recipe : item->getRecipes().get()) {
						for (const auto& [ingredient_name, amount] : recipe.get()) {
							parent_items.insert(at(ingredient_name));
						}
					}
				} catch (NotUsedException& e) {
					// Item has no recipes, thus no parents
				}
			}
		};

		// Item graph
		std::unordered_map<Item*, ItemNode*> item_graph;

		// Master node
		class MasterItem final : public Item {
			public:
				MasterItem() : Item("Master Item", "") {}
		};
		auto master_item = new MasterItem;
		auto master_node = new ItemNode;

		// Populate item graph and add every item as child of master node
		for (const auto& [item_name, item] : items) {
			item_graph.insert({ item, new ItemNode(item) });
			master_node->child_items.insert(item);
		}

		// Insert master node into item graph
		item_graph.insert({ master_item, master_node });

		// Store unordered set of all children for each item
		for (const auto& [item, item_node] : item_graph) {
			for (const auto& parent : item_node->parent_items) {
				item_graph.at(parent)->child_items.insert(item);
			}
		}

		// Recursive lambda function for finding item update order
		std::function<std::list<Item*>(Item*)> find_item_update_order = [&](Item* item) {
			// Get item node for this item
			auto& [parent_items, child_items, item_update_order_items, item_update_order, completed] = *item_graph.at(item);

			// Return early if item already completed
			if (completed) {
				return item_update_order;
			}

			// Build item update order from item update order of children
			if (!child_items.empty()) {
				// Take item update order from first child as a starting point
				auto it = child_items.begin();
				item_update_order = find_item_update_order(*it);
				item_update_order_items = item_graph.at(*it)->item_update_order_items;
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
			try {
				item->setItemUpdateOrder(find_item_update_order(item));
			} catch (NotUsedException& e) {
				// Item does not use item update order
			}
		}

		// Save return value
		master_node->item_update_order.pop_front();
		std::list<Item*> master_item_update_order = master_node->item_update_order;

		// Delete created objects
		delete master_item;
		for (const auto& [item, item_node] : item_graph) {
			delete item_node;
		}

		// Return master item update order
		return master_item_update_order;
	}

	std::unordered_map<std::string, Item*>& get() {
		return items;
	}

	std::pair<Recipe, double> getBestInstantCraft(Item* item) {
		Recipe best_instant_craft_recipe;
		double best_instant_craft_cost = HUGE_VAL;

		for (auto& recipe : item->getRecipes().get()) {
			// Calculate the total cost of the ingredients in the recipe
			double recipe_cost = 0.;
			for (const auto& [ingredient_name, amount] : recipe.get()) {
				recipe_cost += amount * at(ingredient_name)->getBestInstantAcquireCost();
			}

			// Calculate the instant craft cost of the recipe
			const double instant_craft_cost = (recipe_cost + item->getCraftTax()) / item->getYield(recipe);

			// Update best instant craft if current instant craft is better
			if (instant_craft_cost < best_instant_craft_cost) {
				best_instant_craft_recipe = recipe;
				best_instant_craft_cost = instant_craft_cost;
			}
		}

		// Return the best instant craft
		return { best_instant_craft_recipe, best_instant_craft_cost };
	}

	std::pair<Recipe, double> getBestCraft(Item* item) {
		Recipe best_craft_recipe;
		double best_craft_cost = HUGE_VAL;

		for (auto& recipe : item->getRecipes().get()) {
			// Calculate the total cost of the ingredients in the recipe
			double recipe_cost = 0.;
			for (const auto& [ingredient_name, amount] : recipe.get()) {
				recipe_cost += amount * at(ingredient_name)->getBestAcquireCost();
			}

			// Calculate the craft cost of the recipe
			const double craft_cost = (recipe_cost + item->getCraftTax()) / item->getYield(recipe);

			// Update the best craft is current craft is better
			if (craft_cost < best_craft_cost) {
				best_craft_recipe = recipe;
				best_craft_cost = craft_cost;
			}
		}

		// Return the best craft
		return { best_craft_recipe, best_craft_cost };
	}

	double profitMargin(const double sell_price, const double acquire_cost) {
		return (sell_price - acquire_cost) / sell_price;
	}
}
