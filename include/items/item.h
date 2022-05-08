#pragma once

#include "recipes.h"

class Item {
	public:
		Item();
		virtual ~Item();

		virtual bool getBuyEqualsSell();
		virtual void setBuyEqualsSell(bool buy_equals_sell);

		virtual double getSellPrice();
		virtual void setSellPrice(double sell_price);

		virtual double getBuyPrice();
		virtual void setBuyPrice(double buy_price);

		virtual double getBaseProc();

		virtual double getBaseCraftTax();

		virtual Recipes* getRecipes();

		virtual std::string getImagePath();

		virtual double getSellCraftCost();
		virtual double updateSellCraftCost();

		virtual double getBuyCraftCost();
		virtual double updateBuyCraftCost();

		virtual double getSellProfitMargin();
		virtual double updateSellProfitMargin();

		virtual double getBuyProfitMargin();
		virtual double updateBuyProfitMargin();

	protected:
		bool buy_equals_sell = true;
		double sell_price = 0;
		double buy_price = 0;
		double base_proc = 0;
		double base_craft_tax = 0;
		Recipes* recipes = nullptr;
		std::string image_path;
		double sell_craft_cost = 0;
		double buy_craft_cost = 0;
		double sell_profit_margin = 0;
		double buy_profit_margin = 0;
};

