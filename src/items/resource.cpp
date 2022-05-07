#include "items/resource.h"

Resource::Resource() = default;

bool Resource::getBuyEqualsSell() {
	return buy_equals_sell;
}

void Resource::setBuyEqualsSell(const bool buy_equals_sell) {
	this->buy_equals_sell = buy_equals_sell;
}

void Resource::setSellPrice(const double sell_price) {
	this->sell_price = sell_price;

	if (buy_equals_sell) {
		setBuyPrice(sell_price);
	}
}

double Resource::getBuyPrice() {
	return buy_price;
}

void Resource::setBuyPrice(const double buy_price) {
	this->buy_price = buy_price;
}
