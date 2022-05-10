#pragma once

#include "items/resources/refined_resources/refined_resource.h"

class Planks final : public RefinedResource {
	public:
		Planks(const std::string& item_name,
			   int tier,
			   bool buy_equals_sell,
			   double sell_price,
			   double buy_price,
			   double base_yield,
			   double base_craft_tax,
			   Recipes* recipes,
			   const std::string& image_path);

		double getCraftTax(Settings& settings) override;
		double getYield(Recipe& recipe, Settings& settings) override;
};
