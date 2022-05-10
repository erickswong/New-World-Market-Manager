#include "items/item.h"

#include <algorithm>

#include "exceptions.h"

Item::Item() = default;

Item::~Item() {
	delete recipes;
}

double Item::bestInstantAcquireCost() {
	return std::min(sell_price, analysis.instant_craft_cost);
}

double Item::bestAcquireCost() {
	return std::min({ sell_price, analysis.instant_craft_cost, analysis.best_craft_cost, buy_price });
}

double Item::craftTax(Settings& settings) {
	throw NotUsedException();
}

double Item::proc(Recipe& recipe, Settings& settings) {
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

bool Item::setBuyEqualsSell(bool buy_equals_sell) {
	return false;
}

double Item::getSellPrice() {
	return sell_price;
}

bool Item::setSellPrice(double sell_price) {
	this->sell_price = sell_price;

	return false;
}

double Item::getBuyPrice() {
	throw NotUsedException();
}

bool Item::setBuyPrice(double buy_price) {
	return false;
}

double Item::getBaseProc() {
	throw NotUsedException();
}

double Item::getBaseCraftTax() {
	throw NotUsedException();
}

Recipes* Item::getRecipes() {
	throw NotUsedException();
}

std::string Item::getImagePath() {
	return image_path;
}

ItemAnalysis& Item::getAnalysis() {
	throw NotUsedException();
}
