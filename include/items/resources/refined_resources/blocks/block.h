#pragma once

#include "items/resources/refined_resources/refined_resource.h"

class Block final : public RefinedResource {
	public:
		Block(std::string item_name,
		       std::string image_path,
		       int tier,
		       bool buy_equals_sell,
			   double sell_price,
			   double buy_price,
			   double base_yield,
			   double base_craft_tax,
		       const Recipes& recipes);
		explicit Block(Json::Value json_value);

		[[nodiscard]] Json::Value toJson() const override;

		double getCraftTax(Settings& settings) override;
		double getYield(Recipe& recipe, Settings& settings) override;
};
