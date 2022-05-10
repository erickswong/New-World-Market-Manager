#pragma once

#include "items/resources/resource.h"

class RefinedResource : public Resource {
	public:
		RefinedResource();

		bool setBuyEqualsSell(bool buy_equals_sell) override;

		bool setSellPrice(double sell_price) override;

		bool setBuyPrice(double buy_price) override;

		double getBaseProc() override;

		double getBaseCraftTax() override;

		Recipes* getRecipes() override;

		ItemAnalysis& getAnalysis() override;

	protected:
		static double refiningComponentYieldBonus(int refined_resource_tier, int refining_component_tier);
};
