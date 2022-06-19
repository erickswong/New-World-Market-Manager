export module items:refined_resource;

import :resource;

namespace items {
	export class RefinedResource : public Resource {
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
			/**
			 * @brief Returns a json representing this object
			 * 
			 * @return The json
			 */
			[[nodiscard]] Json::Value toJson() const override;

			double getBaseYield() override;

			double getBaseCraftTax() override;

			Recipes& getRecipes() override;

			ItemAnalysis& getAnalysis() override;

		protected:
			static double refiningComponentYieldBonus(int refined_resource_tier, int refining_component_tier);
	};
};
