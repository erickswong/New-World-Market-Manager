#include "items/refining_component.h"

RefiningComponent::RefiningComponent(const bool buy_equals_sell,
									 const double sell_price,
                                     const double buy_price,
                                     const std::string image_path) {
	this->buy_equals_sell = buy_equals_sell;
	this->sell_price = sell_price;
	this->buy_price = buy_price;
	this->image_path = image_path;
}
