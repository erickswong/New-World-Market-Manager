#include <cmath>

#include "items/items.h"

Items::~Items() {
	// Delete each item in items
	for (const auto& [item_name, item] : items) {
		delete item;
	}
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
