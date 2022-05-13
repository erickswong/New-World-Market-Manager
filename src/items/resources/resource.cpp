#include "items/resources/resource.h"

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

bool Resource::setSellPrice(const float sell_price) {
	if (this->sell_price != sell_price) {
		this->sell_price = sell_price;

		if (buy_equals_sell) {
			buy_price = sell_price;
		}
	}

	return false;
}

float Resource::getBuyPrice() {
	return buy_price;
}

bool Resource::setBuyPrice(const float buy_price) {
	if (this->buy_price != buy_price) {
		this->buy_price = buy_price;
	}

	return false;
}