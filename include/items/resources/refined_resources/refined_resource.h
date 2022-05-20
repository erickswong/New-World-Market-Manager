#pragma once

#include "items/resources/resource.h"

class RefinedResource : public Resource {
	public:
		RefinedResource(std::string item_name,
						std::string image_path,
						int tier,
						bool buy_equals_sell,
						double sell_price,
						double buy_price,
						double base_yield,
						double base_craft_tax,
						const Recipes& recipes);
		explicit RefinedResource(Json::Value json_value);

		[[nodiscard]] Json::Value toJson() const override;

		bool setBuyEqualsSell(bool buy_equals_sell) override;

		bool setSellPrice(double sell_price) override;

		bool setBuyPrice(double buy_price) override;

		double getBaseYield() override;

		double getBaseCraftTax() override;

		Recipes& getRecipes() override;

		ItemAnalysis& getAnalysis() override;

	protected:
		static double refiningComponentYieldBonus(int refined_resource_tier, int refining_component_tier);
};
