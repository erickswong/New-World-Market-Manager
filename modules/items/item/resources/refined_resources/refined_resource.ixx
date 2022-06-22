export module items:refined_resource;

import :resource;

namespace items {

	export class RefinedResource : public Resource {
		double base_yield;
		double base_craft_tax;
		Recipes recipes;
		double best_instant_craft_cost = HUGE_VAL;
		double best_craft_cost         = HUGE_VAL;
		Recipe best_instant_recipe;
		Recipe best_recipe;
			
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
			explicit RefinedResource(const Json::Value& json_value);

		public:
			virtual ~RefinedResource() = default;

			// Returns a json representing this object
			[[nodiscard]] Json::Value toJson() const override;

			// Returns the best instant acquire cost
			[[nodiscard]] double bestInstantAcquireCost() const override;
			// Returns the best acquire cost
			[[nodiscard]] double bestAcquireCost() const override;

			// Returns the best instant profit margin
			[[nodiscard]] double bestInstantMargin() const;
			// Returns the best profit margin
			[[nodiscard]] double bestMargin() const;

			// Returns the best instant markup percentage
			[[nodiscard]] double bestInstantMarkup() const;
			// Returns the best markup percentage
			[[nodiscard]] double bestMarkup() const;

			// Returns the craft tax
			[[nodiscard]] virtual double craftTax() const = 0;

			// Returns the yield when using the given recipe
			[[nodiscard]] virtual double yield(const Recipe& recipe) const = 0;

			// Returns base_yield
			[[nodiscard]] double getBaseYield() const;

			// Returns base_craft_tax
			[[nodiscard]] double getBaseCraftTax() const;

			// Returns recipes
			const Recipes& getRecipes() const;

			// Returns best_instant_craft_cost
			[[nodiscard]] double getBestInstantCraftCost() const;
			// Sets best_instant_craft_cost
			void setBestInstantCraftCost(double best_instant_craft_cost);

			// Returns best_craft_cost
			[[nodiscard]] double getBestCraftCost() const;
			// Sets best_craft_cost
			void setBestCraftCost(double best_craft_cost);

			// Returns best_instant_recipe
			[[nodiscard]] const Recipe& getBestInstantRecipe() const;
			// Sets best_instant_recipe
			void setBestInstantRecipe(Recipe best_instant_recipe);

			// Returns best_recipe
			[[nodiscard]] const Recipe& getBestRecipe() const;
			// Sets best_recipe
			void setBestRecipe(Recipe best_recipe);

		protected:
			// Returns the yield bonus contributed by the refining component
			static double refiningComponentYieldBonus(int refined_resource_tier, int refining_component_tier);

		private:
			// Returns the profit margin given by sell_price and acquire_cost
			static double margin(const double sell_price, const double acquire_cost);

			// Returns the markup percentage given by sell_price and acquire_cost
			static double markup(const double sell_price, const double acquire_cost);
	};
};
