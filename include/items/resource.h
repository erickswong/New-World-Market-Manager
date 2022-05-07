#pragma once

#include "item.h"

class Resource : public Item {
	public:
		Resource();

		bool getBuyEqualsSell() override;
		void setBuyEqualsSell(bool buy_equals_sell) override;
		
		void setSellPrice(double sell_price) override;

		double getBuyPrice() override;
		void setBuyPrice(double buy_price) override;
};
