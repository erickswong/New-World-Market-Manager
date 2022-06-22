export module items:refined_resource;

import :resource;

namespace items {
	export struct ItemAnalysis { // TODO: rename to Analysis, move into RefinedResource
		double best_instant_craft_cost = HUGE_VAL;
		double best_craft_cost = HUGE_VAL;
		double best_instant_profit_margin = -HUGE_VAL;
		double best_profit_margin = -HUGE_VAL;
		Recipe best_instant_recipe;
		Recipe best_recipe;
	};

	export class RefinedResource : public Resource {
		double base_yield;
		double base_craft_tax;
		Recipes recipes;
		ItemAnalysis analysis;
			
		protected:
			RefinedResource(const std::string& item_name,
							const std::string& image_path,
							int tier,
							bool buy_equals_sell,
							double sell_price,
							double buy_price,
							double base_yield,
							double base_craft_tax,
							const Recipes& recipes);
			explicit RefinedResource(Json::Value json_value);

		public:
			virtual ~RefinedResource() = default;

			// Returns a json representing this object
			[[nodiscard]] Json::Value toJson() const override;

			// Returns the best instant acquire cost
			[[nodiscard]] double bestInstantAcquireCost() override;

			// Returns the best acquire cost
			[[nodiscard]] double bestAcquireCost() override;

			// Returns the craft tax
			[[nodiscard]] virtual double craftTax() = 0;

			// Returns the yield when using the given recipe
			[[nodiscard]] virtual double yield(Recipe& recipe) = 0;

			// Returns base_yield
			[[nodiscard]] double getBaseYield();

			// Returns base_craft_tax
			[[nodiscard]] double getBaseCraftTax();

			// Returns recipes
			Recipes& getRecipes();

			// Returns analysis
			[[nodiscard]] ItemAnalysis& getAnalysis();

		protected:
			// Returns the yield bonus contributed by the refining component
			static double refiningComponentYieldBonus(int refined_resource_tier, int refining_component_tier);
	};
};
