#include "items/item.h"

#include <algorithm>

#include "exceptions.h"

Item::~Item() = default;

float Item::getBestInstantAcquireCost() {
	return std::min(sell_price, analysis.best_instant_craft_cost);
}

float Item::getBestAcquireCost() {
	return std::min({ sell_price, analysis.best_instant_craft_cost, analysis.best_craft_cost, buy_price });
}

float Item::getCraftTax(Settings& settings) {
	throw NotUsedException();
}

float Item::getYield(Recipe& recipe, Settings& settings) {
	throw NotUsedException();
}

std::string Item::getItemName() {
	return item_name;
}

int Item::getTier() {
	return tier;
}

bool Item::getBuyEqualsSell() {
	throw NotUsedException();
}

bool Item::setBuyEqualsSell(const bool buy_equals_sell) {
	return false;
}

float Item::getSellPrice() {
	return sell_price;
}

bool Item::setSellPrice(const float sell_price) {
	this->sell_price = sell_price;

	return false;
}

float Item::getBuyPrice() {
	throw NotUsedException();
}

bool Item::setBuyPrice(const float buy_price) {
	return false;
}

float Item::getBaseYield() {
	throw NotUsedException();
}

float Item::getBaseCraftTax() {
	throw NotUsedException();
}

Recipes& Item::getRecipes() {
	throw NotUsedException();
}

std::string Item::getImagePath() {
	return image_path;
}

ItemAnalysis& Item::getAnalysis() {
	throw NotUsedException();
}
