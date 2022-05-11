#pragma once

#include "items/item.h"

class Resource : public Item {
	public:
		bool getBuyEqualsSell() override;
		bool setBuyEqualsSell(bool buy_equals_sell) override;
		
		bool setSellPrice(float sell_price) override;

		float getBuyPrice() override;
		bool setBuyPrice(float buy_price) override;
};
