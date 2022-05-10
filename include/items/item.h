#pragma once

#include <include/recipes/recipes.h>
#include "settings/settings.h"

struct ItemAnalysis {
	double instant_craft_cost = HUGE_VAL;
	double best_craft_cost = HUGE_VAL;
	double instant_profit_margin = -HUGE_VAL;
	double best_profit_margin = -HUGE_VAL;
};

class Item {
	public:
		Item();
		virtual ~Item();
		
		virtual double getBestInstantAcquireCost();
		virtual double getBestAcquireCost();
		virtual double getCraftTax(Settings& settings);
		virtual double getYield(Recipe& recipe, Settings& settings);

		virtual std::string getItemName();

		virtual int getTier();

		virtual bool getBuyEqualsSell();
		virtual bool setBuyEqualsSell(bool buy_equals_sell);

		virtual double getSellPrice();
		virtual bool setSellPrice(double sell_price);

		virtual double getBuyPrice();
		virtual bool setBuyPrice(double buy_price);

		virtual double getBaseYield();

		virtual double getBaseCraftTax();

		virtual Recipes* getRecipes();

		virtual std::string getImagePath();
		
		virtual ItemAnalysis& getAnalysis();

	protected:
		std::string item_name;
		int tier = 0;
		bool buy_equals_sell = true;
		double sell_price = HUGE_VAL;
		double buy_price = HUGE_VAL;
		double base_yield = 0;
		double base_craft_tax = 0;
		Recipes* recipes = nullptr;
		std::string image_path;

		ItemAnalysis analysis;
};
