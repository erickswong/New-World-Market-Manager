#include "items/item.h"

#include "exceptions.h"

Item::Item() = default;

Item::~Item() = default;

bool Item::getBuyEqualsSell() {
	throw NotUsedException();
}

void Item::setBuyEqualsSell(bool buy_equals_sell) {
	throw NotUsedException();
}

double Item::getSellPrice() {
	return sell_price;
}

void Item::setSellPrice(const double sell_price) {
	this->sell_price = sell_price;
}

double Item::getBuyPrice() {
	throw NotUsedException();
}

void Item::setBuyPrice(double buy_price) {
	throw NotUsedException();
}

double Item::getBaseProc() {
	throw NotUsedException();
}

double Item::getBaseCraftTax() {
	throw NotUsedException();
}

Recipes Item::getRecipes() {
	throw NotUsedException();
}

std::string Item::getImagePath() {
	return image_path;
}

double Item::getSellCraftCost() {
	throw NotUsedException();
}

double Item::updateSellCraftCost() {
	throw NotUsedException();
}

double Item::getBuyCraftCost() {
	throw NotUsedException();
}

double Item::updateBuyCraftCost() {
	throw NotUsedException();
}

double Item::getSellProfitMargin() {
	throw NotUsedException();
}

double Item::updateSellProfitMargin() {
	throw NotUsedException();
}

double Item::getBuyProfitMargin() {
	throw NotUsedException();
}

double Item::updateBuyProfitMargin() {
	throw NotUsedException();
}
