#include "items/items.h"

Items::Items() : items(new std::map<std::string, Item*>()) {
}

Items::~Items() {
	// Delete each item in items
	for (const auto& [item_name, item] : *items) {
		delete item;
	}

	delete items;
}

void Items::addItem(const std::string& item_name, Item* item) const {
	items->insert({ item_name, item });
}

double Items::itemBestInstantAcquireCost(const std::string& item_name) const {
	return getItem(item_name)->bestInstantAcquireCost();
}

double Items::itemBestAcquireCost(const std::string& item_name) const {
	return getItem(item_name)->bestAcquireCost();
}

double Items::itemCraftTax(const std::string& item_name, Settings& settings) const {
	return getItem(item_name)->craftTax(settings);
}

double Items::itemProc(const std::string& item_name, Recipe& recipe, Settings& settings) const {
	return getItem(item_name)->proc(recipe, settings);
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
	return getItem(item_name)->getBaseProc();
}

double Items::getItemBaseCraftTax(const std::string& item_name) const {
	return getItem(item_name)->getBaseCraftTax();
}

Recipes* Items::getItemRecipes(const std::string& item_name) const {
	return getItem(item_name)->getRecipes();
}

std::string Items::getItemImagePath(const std::string& item_name) const {
	return getItem(item_name)->getImagePath();
}

ItemAnalysis& Items::getItemAnalysis(const std::string& item_name) const {
	return getItem(item_name)->getAnalysis();
}

std::map<std::string, Item*>* Items::getItems() const {
	return items;
}

Item* Items::getItem(const std::string& item_name) const {
	return items->at(item_name);
}

void Items::analyzeItem(const std::string& item_name, Settings& settings) const {
	auto& [instant_craft_cost, best_craft_cost, instant_profit_margin, best_profit_margin] = getItemAnalysis(item_name);
	const double sell_price = getItemSellPrice(item_name);

	instant_craft_cost = itemBestInstantCraftCost(item_name, settings);
	best_craft_cost = itemBestCraftCost(item_name, settings);
	instant_profit_margin = profitMargin(sell_price, instant_craft_cost);
	best_profit_margin = profitMargin(sell_price, best_craft_cost);
}

double Items::itemBestInstantCraftCost(const std::string& item_name, Settings& settings) const {
	double best_instant_craft_cost = HUGE_VAL;

	for (Recipe& recipe : *getItemRecipes(item_name)->getRecipes()) {
		double recipe_cost = 0;

		for (const auto& [ingredient_name, amount] : *recipe.getRecipe()) {
			recipe_cost += amount * itemBestInstantAcquireCost(ingredient_name);
		}

		double instant_craft_cost = (recipe_cost + itemCraftTax(item_name, settings)) / itemProc(item_name, recipe, settings);

		best_instant_craft_cost = std::min(best_instant_craft_cost, instant_craft_cost);
	}

	return best_instant_craft_cost;
}

double Items::itemBestCraftCost(const std::string& item_name, Settings& settings) const {
	double best_craft_cost = HUGE_VAL;

	for (Recipe& recipe : *getItemRecipes(item_name)->getRecipes()) {
		double recipe_cost = 0;

		for (const auto& [ingredient_name, amount] : *recipe.getRecipe()) {
			recipe_cost += amount * itemBestAcquireCost(ingredient_name);
		}

		double craft_cost = (recipe_cost + itemCraftTax(item_name, settings)) / itemProc(item_name, recipe, settings);

		best_craft_cost = std::min(best_craft_cost, craft_cost);
	}

	return best_craft_cost;
}

double Items::profitMargin(const double sell_price, const double acquire_cost) {
	return (sell_price - acquire_cost) / sell_price;
}
