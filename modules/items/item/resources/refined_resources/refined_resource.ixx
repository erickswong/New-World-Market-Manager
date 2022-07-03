export module items:refined_resource;

import recipe_book;

import :resource;

namespace items {

	export class RefinedResource : public Resource {
		double base_yield;
		double base_craft_tax;
		double best_instant_craft_cost = HUGE_VAL;
		double best_craft_cost         = HUGE_VAL;
		recipe_book::Recipe best_instant_recipe;
		recipe_book::Recipe best_recipe;
			
		protected:
			RefinedResource(const std::string& item_name,
							int tier,
							bool buy_equals_sell,
							double sell_price,
							double buy_price,
							double base_yield,
							double base_craft_tax);
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

			// Returns the yield
			[[nodiscard]] virtual double yield() const = 0;

			// Returns base_yield
			[[nodiscard]] double getBaseYield() const;

			// Returns base_craft_tax
			[[nodiscard]] double getBaseCraftTax() const;

			// Returns best_instant_craft_cost
			[[nodiscard]] double getBestInstantCraftCost() const;
			// Sets best_instant_craft_cost
			void setBestInstantCraftCost(double best_instant_craft_cost);

			// Returns best_craft_cost
			[[nodiscard]] double getBestCraftCost() const;
			// Sets best_craft_cost
			void setBestCraftCost(double best_craft_cost);

			// Returns best_instant_recipe
			[[nodiscard]] const recipe_book::Recipe& getBestInstantRecipe() const;
			// Sets best_instant_recipe
			void setBestInstantRecipe(recipe_book::Recipe best_instant_recipe);

			// Returns best_recipe
			[[nodiscard]] const recipe_book::Recipe& getBestRecipe() const;
			// Sets best_recipe
			void setBestRecipe(recipe_book::Recipe best_recipe);

		protected:
			// Returns the yield bonus contributed by the refining component
			double refiningComponentYieldBonus(int refined_resource_tier) const;

		private:
			// Returns the profit margin given by sell_price and acquire_cost
			static double margin(const double sell_price, const double acquire_cost);

			// Returns the markup percentage given by sell_price and acquire_cost
			static double markup(const double sell_price, const double acquire_cost);
	};
};
