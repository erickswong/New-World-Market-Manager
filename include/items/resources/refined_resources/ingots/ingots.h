#pragma once

#include "items/resources/refined_resources/refined_resource.h"

class Ingots final : public RefinedResource {
	public:
		Ingots(const std::string& item_name,
			   bool buy_equals_sell,
		       double sell_price,
		       double buy_price,
		       double base_proc,
		       double base_craft_tax,
		       Recipes* recipes,
		       const std::string& image_path);

		double craftTax(Settings& settings) override;
		double proc(Recipe& recipe, Settings& settings) override;
};

