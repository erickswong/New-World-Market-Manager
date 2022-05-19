#include "items/item.h"

#include "exceptions.h"

Item::Item(std::string item_name,
           std::string image_path)
			   : item_name(std::move(item_name)),
                 image_path(std::move(image_path)) {
}

Item::~Item() = default;

double Item::getBestInstantAcquireCost() {
	throw NotUsedException();
}

double Item::getBestAcquireCost() {
	throw NotUsedException();
}

double Item::getCraftTax(Settings& settings) {
	throw NotUsedException();
}

double Item::getYield(Recipe& recipe, Settings& settings) {
	throw NotUsedException();
}

std::string Item::getItemName() {
	return item_name;
}

int Item::getTier() {
	throw NotUsedException();
}

bool Item::getBuyEqualsSell() {
	throw NotUsedException();
}

bool Item::setBuyEqualsSell(const bool buy_equals_sell) {
	throw NotUsedException();
}

double Item::getSellPrice() {
	throw NotUsedException();
}

bool Item::setSellPrice(const double sell_price) {
	throw NotUsedException();
}

double Item::getBuyPrice() {
	throw NotUsedException();
}

bool Item::setBuyPrice(const double buy_price) {
	throw NotUsedException();
}

double Item::getBaseYield() {
	throw NotUsedException();
}

double Item::getBaseCraftTax() {
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
