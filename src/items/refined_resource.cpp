#include "items/refined_resource.h"

#include "exceptions.h"

RefinedResource::RefinedResource(const bool buy_equals_sell,
								 const double sell_price,
                                 const double buy_price,
                                 const double base_proc,
                                 const double base_craft_tax,
                                 const Recipes recipes,
                                 const std::string image_path) {
	this->buy_equals_sell = buy_equals_sell;
	this->sell_price = sell_price;
	this->buy_price = buy_price;
	this->base_proc = base_proc;
	this->base_craft_tax = base_craft_tax;
	this->recipes = recipes;
	this->image_path = image_path;
	updateSellCraftCost();
	updateBuyCraftCost();
}

void RefinedResource::setSellPrice(const double sell_price) {
	this->sell_price = sell_price;
	updateSellCraftCost();

	if (buy_equals_sell) {
		setBuyPrice(sell_price);
	}
}

void RefinedResource::setBuyPrice(const double buy_price) {
	this->buy_price = buy_price;
	updateBuyCraftCost();
}

double RefinedResource::getBaseProc() {
	return base_proc;
}

double RefinedResource::getBaseCraftTax() {
	return base_craft_tax;
}

Recipes RefinedResource::getRecipes() {
	return recipes;
}

double RefinedResource::getSellCraftCost() {
	return sell_craft_cost;
}

double RefinedResource::updateSellCraftCost() {
	// TODO: Calculate from recipes, may need to add Items parameter, and in future add Settings parameter
	throw NotImplementedException();

	updateSellProfitMargin();

	return sell_craft_cost;
}

double RefinedResource::getBuyCraftCost() {
	return buy_craft_cost;
}

double RefinedResource::updateBuyCraftCost() {
	// TODO: like updateSellCraftCost()
	throw NotImplementedException();

	updateBuyProfitMargin();

	return buy_craft_cost;
}

double RefinedResource::getSellProfitMargin() {
	return sell_profit_margin;
}

double RefinedResource::updateSellProfitMargin() {
	sell_profit_margin = (sell_price - sell_craft_cost) / sell_price;

	return sell_profit_margin;
}

double RefinedResource::getBuyProfitMargin() {
	return buy_profit_margin;
}

double RefinedResource::updateBuyProfitMargin() {
	buy_profit_margin = (sell_price - buy_craft_cost) / sell_price;

	return buy_profit_margin;
}
