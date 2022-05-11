#pragma once

#include <cmath>

#include "recipes/recipes.h"
#include "settings/settings.h"

struct ItemAnalysis {
	float best_instant_craft_cost = INFINITY;
	float best_craft_cost = INFINITY;
	float best_instant_profit_margin = -INFINITY;
	float best_profit_margin = -INFINITY;
	Recipe best_instant_recipe;
	Recipe best_recipe;
};

class Item {
	public:
		virtual ~Item();
		
		virtual float getBestInstantAcquireCost();
		virtual float getBestAcquireCost();
		virtual float getCraftTax(Settings& settings);
		virtual float getYield(Recipe& recipe, Settings& settings);

		virtual std::string getItemName();

		virtual int getTier();

		virtual bool getBuyEqualsSell();
		virtual bool setBuyEqualsSell(bool buy_equals_sell);

		virtual float getSellPrice();
		virtual bool setSellPrice(float sell_price);

		virtual float getBuyPrice();
		virtual bool setBuyPrice(float buy_price);

		virtual float getBaseYield();

		virtual float getBaseCraftTax();

		virtual Recipes& getRecipes();

		virtual std::string getImagePath();
		
		virtual ItemAnalysis& getAnalysis();

	protected:
		std::string item_name;
		int tier = 0;
		bool buy_equals_sell = true;
		float sell_price = INFINITY;
		float buy_price = INFINITY;
		float base_yield = 0.f;
		float base_craft_tax = 0.f;
		Recipes recipes;
		std::string image_path;

		ItemAnalysis analysis;
};
