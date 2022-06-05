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

Items::Items() {
	DefaultItemsInitializer(this).initializeItems();
}

Items::Items(Json::Value json_value) {
	for (const std::string& item_name : json_value.getMemberNames()) {
		std::string item_type = json_value[item_name]["item_type"].asString();

		if (item_type == "Item") {
			addItem(item_name, new Item(json_value[item_name]));
		} else if (item_type == "Resource") {
			addItem(item_name, new Resource(json_value[item_name]));
		} else if (item_type == "RawResource") {
			addItem(item_name, new RawResource(json_value[item_name]));
		} else if (item_type == "RefinedResource") {
			addItem(item_name, new RefinedResource(json_value[item_name]));
		} else if (item_type == "Block") {
			addItem(item_name, new Block(json_value[item_name]));
		} else if (item_type == "Cloth") {
			addItem(item_name, new Cloth(json_value[item_name]));
		} else if (item_type == "Ingot") {
			addItem(item_name, new Ingot(json_value[item_name]));
		} else if (item_type == "Leather") {
			addItem(item_name, new Leather(json_value[item_name]));
		} else if (item_type == "Plank") {
			addItem(item_name, new Plank(json_value[item_name]));
		} else if (item_type == "RefiningComponent") {
			addItem(item_name, new RefiningComponent(json_value[item_name]));
		} else {
			throw BadJsonException("Unrecognized item_type in items.json");
		}
	}

	setItemUpdateOrders();
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

void Items::addItem(const std::string& item_name, Item* item) {
	items.insert({ item_name, item });
}

void Items::analyzeItem(const std::string& item_name, Settings& settings) const {
	auto& [best_instant_craft_cost, best_craft_cost, best_instant_profit_margin, best_profit_margin, best_instant_recipe, best_recipe] = getItemAnalysis(item_name);
	const double sell_price = getItemSellPrice(item_name);
	const std::tuple<Recipe*, double> best_instant_craft = itemBestInstantCraftCost(item_name, settings);
	const std::tuple<Recipe*, double> best_craft = itemBestCraftCost(item_name, settings);

	best_instant_craft_cost = std::get<1>(best_instant_craft);
	best_craft_cost = std::get<1>(best_craft);
	best_instant_profit_margin = profitMargin(sell_price, best_instant_craft_cost);
	best_profit_margin = profitMargin(sell_price, best_craft_cost);
	best_instant_recipe = *std::get<0>(best_instant_craft);
	best_recipe = *std::get<0>(best_craft);
}

double Items::getItemBestInstantAcquireCost(const std::string& item_name) const {
	return getItem(item_name)->getBestInstantAcquireCost();
}

double Items::getItemBestAcquireCost(const std::string& item_name) const {
	return getItem(item_name)->getBestAcquireCost();
}

double Items::getItemCraftTax(const std::string& item_name, Settings& settings) const {
	return getItem(item_name)->getCraftTax(settings);
}

double Items::getItemYield(const std::string& item_name, Recipe& recipe, Settings& settings) const {
	return getItem(item_name)->getYield(recipe, settings);
}

int Items::getItemTier(const std::string& item_name) const {
	return getItem(item_name)->getTier();
}

bool Items::getItemBuyEqualsSell(const std::string& item_name) const {
	return getItem(item_name)->getBuyEqualsSell();
}

void Items::setItemBuyEqualsSell(const std::string& item_name, const bool buy_equals_sell, Settings& settings) const {
	if (getItem(item_name)->setBuyEqualsSell(buy_equals_sell)) {
		analyzeItem(item_name, settings);
	}
}

double Items::getItemSellPrice(const std::string& item_name) const {
	return getItem(item_name)->getSellPrice();
}

void Items::setItemSellPrice(const std::string& item_name, const double sell_price, Settings& settings) const {
	if (getItem(item_name)->setSellPrice(sell_price)) {
		analyzeItem(item_name, settings);
	}
}

double Items::getItemBuyPrice(const std::string& item_name) const {
	return getItem(item_name)->getBuyPrice();
}

void Items::setItemBuyPrice(const std::string& item_name, const double buy_price, Settings& settings) const {
	if (getItem(item_name)->setBuyPrice(buy_price)) {
		analyzeItem(item_name, settings);
	}
}

double Items::getItemBaseProc(const std::string& item_name) const {
	return getItem(item_name)->getBaseYield();
}

double Items::getItemBaseCraftTax(const std::string& item_name) const {
	return getItem(item_name)->getBaseCraftTax();
}

Recipes& Items::getItemRecipes(const std::string& item_name) const {
	return getItem(item_name)->getRecipes();
}

std::string Items::getItemImagePath(const std::string& item_name) const {
	return getItem(item_name)->getImagePath();
}

ItemAnalysis& Items::getItemAnalysis(const std::string& item_name) const {
	return getItem(item_name)->getAnalysis();
}

Item* Items::getItem(const std::string& item_name) const {
	return items.at(item_name);
}

std::unordered_map<std::string, Item*> Items::getItems() const {
	return items;
}

std::tuple<Recipe*, double> Items::itemBestInstantCraftCost(const std::string& item_name, Settings& settings) const {
	Recipe* best_instant_craft_recipe = nullptr;
	double best_instant_craft_cost = HUGE_VAL;
	
	for (Recipe& recipe : getItemRecipes(item_name).getRecipes()) {
		// Calculate the total cost of the ingredients in the recipe
		double recipe_cost = 0.;
		for (const auto& [ingredient_name, amount] : recipe.getRecipe()) {
			recipe_cost += amount * getItemBestInstantAcquireCost(ingredient_name);
		}

		// Calculate the instant craft cost of the recipe
		const double instant_craft_cost = (recipe_cost + getItemCraftTax(item_name, settings)) / getItemYield(item_name, recipe, settings);

		// Update best instant craft if current instant craft is better
		if (instant_craft_cost < best_instant_craft_cost) {
			best_instant_craft_recipe = &recipe;
			best_instant_craft_cost = instant_craft_cost;
		}
	}

	// Return the best instant craft
	return { best_instant_craft_recipe, best_instant_craft_cost };
}

std::tuple<Recipe*, double> Items::itemBestCraftCost(const std::string& item_name, Settings& settings) const {
	Recipe* best_craft_recipe = nullptr;
	double best_craft_cost = HUGE_VAL;

	for (Recipe& recipe : getItemRecipes(item_name).getRecipes()) {
		// Calculate the total cost of the ingredients in the recipe
		double recipe_cost = 0.;
		for (const auto& [ingredient_name, amount] : recipe.getRecipe()) {
			recipe_cost += amount * getItemBestAcquireCost(ingredient_name);
		}

		// Calculate the craft cost of the recipe
		const double craft_cost = (recipe_cost + getItemCraftTax(item_name, settings)) / getItemYield(item_name, recipe, settings);

		// Update the best craft is current craft is better
		if (craft_cost < best_craft_cost) {
			best_craft_recipe = &recipe;
			best_craft_cost = craft_cost;
		}
	}

	// Return the best craft
	return { best_craft_recipe, best_craft_cost };
}

double Items::profitMargin(const double sell_price, const double acquire_cost) {
	return (sell_price - acquire_cost) / sell_price;
}

void Items::setItemUpdateOrders() {
	// Item node
	struct ItemNode {
		std::unordered_set<Item*> parent_items;
		std::unordered_set<Item*> child_items;
		std::unordered_set<Item*> item_update_order_items;
		std::list<Item*> item_update_order;
		bool completed = false;

		explicit ItemNode(Item* item, const Items* items) {
			// Store unordered set of all parents for this item
			try {
				// Ingredients found in recipes are parents
				for (const auto& recipe : item->getRecipes().getRecipes()) {
					for (const auto& [ingredient_name, amount] : recipe.getRecipe()) {
						parent_items.insert(items->getItem(ingredient_name));
					}
				}
			} catch (NotUsedException& e) {
				// Item has no recipes, thus no parents
			}
		}
	};

	// Item graph
	std::unordered_map<Item*, ItemNode> item_graph;

	// Populate item graph
	for (const auto& [item_name, item] : items) {
		item_graph.insert({ item, ItemNode(item, this) });
	}

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
		try {
			item->setItemUpdateOrder(find_item_update_order(item));
		} catch (NotUsedException& e) {
			// Item does not use item update order
		}
	}
}
