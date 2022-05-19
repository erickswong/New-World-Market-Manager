#include "items/resources/resource.h"

#include <algorithm>
#include <utility>

Resource::Resource(std::string item_name,
                   std::string image_path,
                   const int tier,
                   const bool buy_equals_sell,
                   const double sell_price,
                   const double buy_price)
					   : Item(std::move(item_name),
							  std::move(image_path)) {
	this->tier = tier;
	this->buy_equals_sell = buy_equals_sell;
	this->sell_price = sell_price;
	this->buy_price = buy_price;
}

double Resource::getBestInstantAcquireCost() {
	return std::min(sell_price, analysis.best_instant_craft_cost);
}

double Resource::getBestAcquireCost() {
	return std::min({ sell_price, analysis.best_instant_craft_cost, analysis.best_craft_cost, buy_price });
}

int Resource::getTier() {
	return tier;
}

bool Resource::getBuyEqualsSell() {
	return buy_equals_sell;
}

bool Resource::setBuyEqualsSell(const bool buy_equals_sell) {
	this->buy_equals_sell = buy_equals_sell;

	if (buy_equals_sell && buy_price != sell_price) {
		buy_price = sell_price;
	}

	return false;
}

double Resource::getSellPrice() {
	return sell_price;
}

bool Resource::setSellPrice(const double sell_price) {
	this->sell_price = sell_price;

	if (buy_equals_sell) {
		buy_price = sell_price;
	}

	return false;
}

double Resource::getBuyPrice() {
	return buy_price;
}

bool Resource::setBuyPrice(const double buy_price) {
	this->buy_price = buy_price;

	return false;
}
