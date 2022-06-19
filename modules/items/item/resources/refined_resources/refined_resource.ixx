export module items:refined_resource;

import :resource;

namespace items {
	export class RefinedResource : public Resource {
		protected:
			/**
			 * @brief Construct a new Refined Resource object
			 * 
			 * @param item_name 
			 * @param image_path 
			 * @param tier 
			 * @param buy_equals_sell 
			 * @param sell_price 
			 * @param buy_price 
			 * @param base_yield 
			 * @param base_craft_tax 
			 * @param recipes 
			 */
			RefinedResource(const std::string& item_name,
							const std::string& image_path,
							int tier,
							bool buy_equals_sell,
							double sell_price,
							double buy_price,
							double base_yield,
							double base_craft_tax,
							const Recipes& recipes);

			/**
			 * @brief Construct a new Refined Resource object
			 * 
			 * @param json_value 
			 */
			explicit RefinedResource(Json::Value json_value);

		public:
			/**
			 * @brief Destroy the RefinedResource object
			 */
			virtual ~RefinedResource() = default;

			double getBaseYield() override;

			double getBaseCraftTax() override;

			Recipes& getRecipes() override;

			ItemAnalysis& getAnalysis() override;

		protected:
			static double refiningComponentYieldBonus(int refined_resource_tier, int refining_component_tier);

			/**
			 * @brief Returns a json representing members used in this object
			 * 
			 * @return The json
			 */
			[[nodiscard]] Json::Value membersToJson() const override;
	};
};
