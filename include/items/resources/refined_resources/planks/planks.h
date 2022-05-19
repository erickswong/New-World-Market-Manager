#pragma once

#include "items/resources/refined_resources/refined_resource.h"

class Planks final : public RefinedResource {
	public:
		Planks(std::string item_name,
			   std::string image_path,
			   int tier,
			   bool buy_equals_sell,
			   double sell_price,
			   double buy_price,
			   double base_yield,
			   double base_craft_tax,
			   const Recipes& recipes);

		double getCraftTax(Settings& settings) override;
		double getYield(Recipe& recipe, Settings& settings) override;
};
