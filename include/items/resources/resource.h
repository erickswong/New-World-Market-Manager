#pragma once

#include "items/item.h"

class Resource : public Item {
	public:
		Resource();

		bool getBuyEqualsSell() override;
		bool setBuyEqualsSell(bool buy_equals_sell) override;
		
		bool setSellPrice(double sell_price) override;

		double getBuyPrice() override;
		bool setBuyPrice(double buy_price) override;
};
