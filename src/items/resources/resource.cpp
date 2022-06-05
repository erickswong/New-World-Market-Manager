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
	if (buy_equals_sell) {
		this->buy_price = sell_price;
	} else {
		this->buy_price = buy_price;
	}
}

Resource::Resource(Json::Value json_value)
	: Item(json_value) {
	this->tier = json_value["tier"].asInt();
	this->buy_equals_sell = json_value["buy_equals_sell"].asBool();
	this->sell_price = json_value["sell_price"].asDouble();
	if (buy_equals_sell) {
		this->buy_price = sell_price;
	} else {
		this->buy_price = json_value["buy_price"].asDouble();
	}
}

Json::Value Resource::toJson() const {
	Json::Value json_value = Item::toJson();

	json_value["item_type"] = "Resource";
	json_value["tier"] = tier;
	json_value["buy_equals_sell"] = buy_equals_sell;
	json_value["sell_price"] = sell_price;
	if (!buy_equals_sell) {
		json_value["buy_price"] = buy_price;
	}

	// Uncomment to save item update order in json
	/*{
		Json::Value json_value;
		for (const auto& item : item_update_order) {
			json_value.append(item->getItemName());
		}
		json_value["item_update_order"] = json_value;
	}*/

	return json_value;
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

std::list<Item*> Resource::getItemUpdateOrder() {
	return item_update_order;
}

void Resource::setItemUpdateOrder(std::list<Item*> item_update_order) {
	this->item_update_order = item_update_order;
}
