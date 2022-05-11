#pragma once

#include "items/resources/refined_resources/refined_resource.h"

class Planks final : public RefinedResource {
	public:
		Planks(const std::string& item_name,
			   int tier,
			   bool buy_equals_sell,
			   float sell_price,
			   float buy_price,
			   float base_yield,
			   float base_craft_tax,
			   Recipes recipes,
			   const std::string& image_path);

		float getCraftTax(Settings& settings) override;
		float getYield(Recipe& recipe, Settings& settings) override;
};
