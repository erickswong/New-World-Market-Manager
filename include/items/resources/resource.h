#pragma once

#include "items/item.h"

class Resource : public Item {
	public:
		Resource(std::string item_name,
				 std::string image_path,
				 int tier,
				 bool buy_equals_sell,
				 double sell_price,
				 double buy_price);
		explicit Resource(Json::Value json_value);

		[[nodiscard]] Json::Value toJson() const override;

		double getBestInstantAcquireCost() override;
		double getBestAcquireCost() override;

		int getTier() override;

		bool getBuyEqualsSell() override;
		bool setBuyEqualsSell(bool buy_equals_sell) override;

		double getSellPrice() override;
		bool setSellPrice(double sell_price) override;

		double getBuyPrice() override;
		bool setBuyPrice(double buy_price) override;
};
