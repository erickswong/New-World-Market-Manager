#pragma once

#include "items.h"
#include "recipe.h"
#include "resource.h"
#include "settings/settings.h"

class RefinedResource : public Resource {
	public:
		RefinedResource(bool buy_equals_sell,
						double sell_price,
						double buy_price,
						double base_proc,
						double base_craft_tax,
						Recipes* recipes,
						std::string image_path);

		void setSellPrice(double sell_price) override;

		void setBuyPrice(double buy_price) override;

		double getBaseProc() override;

		double getBaseCraftTax() override;

		Recipes* getRecipes() override;

		double getSellCraftCost() override;
		double updateSellCraftCost() override;

		double getBuyCraftCost() override;
		double updateBuyCraftCost() override;

		double getSellProfitMargin() override;
		double updateSellProfitMargin() override;

		double getBuyProfitMargin() override;
		double updateBuyProfitMargin() override;
};
