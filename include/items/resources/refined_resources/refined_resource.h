#pragma once

#include "items/resources/resource.h"

class RefinedResource : public Resource {
	public:
		RefinedResource();

		bool setBuyEqualsSell(bool buy_equals_sell) override;

		bool setSellPrice(float sell_price) override;

		bool setBuyPrice(float buy_price) override;

		float getBaseYield() override;

		float getBaseCraftTax() override;

		Recipes& getRecipes() override;

		ItemAnalysis& getAnalysis() override;

	protected:
		static float refiningComponentYieldBonus(int refined_resource_tier, int refining_component_tier);
};
