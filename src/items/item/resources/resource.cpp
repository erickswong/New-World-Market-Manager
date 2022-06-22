module items:resource;

import std.core;

namespace items {
	Resource::Resource(const std::string& item_name,
					   const std::string& image_path,
					   const int tier,
					   const bool buy_equals_sell,
					   const double sell_price,
					   const double buy_price) :
		Item(item_name,
			 image_path),
		tier(tier),
		buy_equals_sell(buy_equals_sell),
		sell_price(sell_price),
		buy_price(buy_price) {
	}

	Resource::Resource(Json::Value json_value) :
		Item(json_value),
		tier(json_value["tier"].asInt()),
		buy_equals_sell(json_value["buy_equals_sell"].asBool()),
		sell_price(json_value["sell_price"].asDouble()),
		buy_price(json_value["buy_price"].asDouble()) {
	}

	Json::Value Resource::toJson() const {
		Json::Value json_value = Item::toJson();

		json_value["tier"]            = tier;
		json_value["buy_equals_sell"] = buy_equals_sell;
		json_value["sell_price"]      = sell_price;
		json_value["buy_price"]       = buy_price;

		return json_value;
	}

	double Resource::bestInstantAcquireCost() {
		return sell_price;
	}

	double Resource::bestAcquireCost() {
		return std::min(sell_price, buy_price);
	}

	int Resource::getTier() {
		return tier;
	}

	bool Resource::getBuyEqualsSell() {
		return buy_equals_sell;
	}

	bool Resource::setBuyEqualsSell(const bool buy_equals_sell) {
		this->buy_equals_sell = buy_equals_sell;

		if (!buy_equals_sell || buy_price == sell_price) {
			return false;
		}

		buy_price = sell_price;

		return true;
	}

	double Resource::getSellPrice() {
		return sell_price;
	}

	bool Resource::setSellPrice(const double sell_price) {
		if (this->sell_price == sell_price) {
			return false;
		}

		this->sell_price = sell_price;

		if (buy_equals_sell) {
			buy_price = sell_price;
		}

		return true;
	}

	double Resource::getBuyPrice() {
		return buy_price;
	}

	bool Resource::setBuyPrice(const double buy_price) {
		if (this->buy_price == buy_price) {
			return false;
		}

		this->buy_price = buy_price;

		return true;
	}
}
