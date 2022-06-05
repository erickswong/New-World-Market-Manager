#include "items/items.h"

#include <cmath>
#include <filesystem>
#include <fstream>
#include <functional>
#include <unordered_set>

#include "exceptions.h"

#include "items/default_items_initializer.h"
#include "items/resources/raw_resources/raw_resource.h"
#include "items/resources/refined_resources/blocks/block.h"
#include "items/resources/refined_resources/cloths/cloth.h"
#include "items/resources/refined_resources/ingots/ingot.h"
#include "items/resources/refined_resources/leathers/leather.h"
#include "items/resources/refined_resources/planks/plank.h"
#include "items/resources/refining_components/refining_component.h"

Items::Items(Settings* settings) {
	DefaultItemsInitializer(this).initializeItems();
	analyze(setItemUpdateOrders(), settings);
}

Items::Items(Json::Value json_value, Settings* settings) {
	for (const std::string& item_name : json_value.getMemberNames()) {
		std::string item_type = json_value[item_name]["item_type"].asString();

		if (item_type == "Item") {
			insert(item_name, new Item(json_value[item_name]));
		} else if (item_type == "Resource") {
			insert(item_name, new Resource(json_value[item_name]));
		} else if (item_type == "RawResource") {
			insert(item_name, new RawResource(json_value[item_name]));
		} else if (item_type == "RefinedResource") {
			insert(item_name, new RefinedResource(json_value[item_name]));
		} else if (item_type == "Block") {
			insert(item_name, new Block(json_value[item_name]));
		} else if (item_type == "Cloth") {
			insert(item_name, new Cloth(json_value[item_name]));
		} else if (item_type == "Ingot") {
			insert(item_name, new Ingot(json_value[item_name]));
		} else if (item_type == "Leather") {
			insert(item_name, new Leather(json_value[item_name]));
		} else if (item_type == "Plank") {
			insert(item_name, new Plank(json_value[item_name]));
		} else if (item_type == "RefiningComponent") {
			insert(item_name, new RefiningComponent(json_value[item_name]));
		} else {
			throw BadJsonException("Unrecognized item_type in items.json");
		}
	}

	analyze(setItemUpdateOrders(), settings);
}

Items::~Items() {
	// Delete each item in items
	for (const auto& [item_name, item] : items) {
		delete item;
	}
}

void Items::writeToDisk() const {
	// Create data directory if missing
	std::filesystem::create_directory("data");

	// Create items.json file
	std::ofstream file("data/items.json");

	// Write json into file
	Json::StyledWriter styled_writer;
	file << styled_writer.write(toJson());

	// Close file
	file.close();
}

Json::Value Items::toJson() const {
	Json::Value json_value;

	for (const auto& [item_name, item] : items) {
		json_value[item_name] = item->toJson();
	}

	return json_value;
}

std::unordered_map<std::string, Item*>& Items::get() {
	return items;
}

Item* Items::at(const std::string& item_name) const {
	return items.at(item_name);
}

void Items::insert(const std::string& item_name, Item* item) {
	items.insert({ item_name, item });
}

void Items::analyze(Item* item, Settings* settings) const {
	try {
		auto& [best_instant_craft_cost, best_craft_cost, best_instant_profit_margin, best_profit_margin, best_instant_recipe, best_recipe] = item->getAnalysis();
		const auto sell_price = item->getSellPrice();

		std::tie(best_instant_recipe, best_instant_craft_cost) = getBestInstantCraft(item, settings);
		std::tie(best_recipe, best_craft_cost) = getBestCraft(item, settings);

		best_instant_profit_margin = profitMargin(sell_price, best_instant_craft_cost);
		best_profit_margin = profitMargin(sell_price, best_craft_cost);
	} catch (NotUsedException& e) {
		// Item does not use analysis
	}
}

void Items::analyze(const std::list<Item*>& item_update_order, Settings* settings) const {
	for (const auto& item : item_update_order) {
		analyze(item, settings);
	}
}

void Items::setBuyEqualsSell(Item* item, const bool buy_equals_sell, Settings* settings) const {
	if (item->setBuyEqualsSell(buy_equals_sell)) {
		analyze(item->getItemUpdateOrder(), settings);
	}
}

void Items::setSellPrice(Item* item, const double sell_price, Settings* settings) const {
	if (item->setSellPrice(sell_price)) {
		analyze(item->getItemUpdateOrder(), settings);
	}
}

void Items::setBuyPrice(Item* item, const double buy_price, Settings* settings) const {
	if (item->setBuyPrice(buy_price)) {
		analyze(item->getItemUpdateOrder(), settings);
	}
}

std::pair<Recipe, double> Items::getBestInstantCraft(Item* item, Settings* settings) const {
	Recipe best_instant_craft_recipe;
	double best_instant_craft_cost = HUGE_VAL;

	for (auto& recipe : item->getRecipes().get()) {
		// Calculate the total cost of the ingredients in the recipe
		double recipe_cost = 0.;
		for (const auto& [ingredient_name, amount] : recipe.get()) {
			recipe_cost += amount * at(ingredient_name)->getBestInstantAcquireCost();
		}

		// Calculate the instant craft cost of the recipe
		const double instant_craft_cost = (recipe_cost + item->getCraftTax(settings)) / item->getYield(recipe, settings);

		// Update best instant craft if current instant craft is better
		if (instant_craft_cost < best_instant_craft_cost) {
			best_instant_craft_recipe = recipe;
			best_instant_craft_cost = instant_craft_cost;
		}
	}

	// Return the best instant craft
	return { best_instant_craft_recipe, best_instant_craft_cost };
}

std::pair<Recipe, double> Items::getBestCraft(Item* item, Settings* settings) const {
	Recipe best_craft_recipe;
	double best_craft_cost = HUGE_VAL;

	for (auto& recipe : item->getRecipes().get()) {
		// Calculate the total cost of the ingredients in the recipe
		double recipe_cost = 0.;
		for (const auto& [ingredient_name, amount] : recipe.get()) {
			recipe_cost += amount * at(ingredient_name)->getBestAcquireCost();
		}

		// Calculate the craft cost of the recipe
		const double craft_cost = (recipe_cost + item->getCraftTax(settings)) / item->getYield(recipe, settings);

		// Update the best craft is current craft is better
		if (craft_cost < best_craft_cost) {
			best_craft_recipe = recipe;
			best_craft_cost = craft_cost;
		}
	}

	// Return the best craft
	return { best_craft_recipe, best_craft_cost };
}

double Items::profitMargin(const double sell_price, const double acquire_cost) {
	return (sell_price - acquire_cost) / sell_price;
}

std::list<Item*> Items::setItemUpdateOrders() {
	// Item node
	struct ItemNode {
		std::unordered_set<Item*> parent_items;
		std::unordered_set<Item*> child_items;
		std::unordered_set<Item*> item_update_order_items;
		std::list<Item*> item_update_order;
		bool completed = false;

		ItemNode() = default;

		ItemNode(Item* item, const Items* items) {
			// Store unordered set of all parents for this item
			try {
				// Ingredients found in recipes are parents
				for (auto& recipe : item->getRecipes().get()) {
					for (const auto& [ingredient_name, amount] : recipe.get()) {
						parent_items.insert(items->at(ingredient_name));
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
	auto master_item = new Item("Master Node", "");
	auto master_node = new ItemNode;

	// Populate item graph and add every item as child of master node
	for (const auto& [item_name, item] : items) {
		item_graph.insert({ item, new ItemNode(item, this) });
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
