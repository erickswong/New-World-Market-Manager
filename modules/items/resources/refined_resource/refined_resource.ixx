export module items:refined_resource;

import :resource;

export class RefinedResource : public Resource {
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

		double getBaseYield() override;

		double getBaseCraftTax() override;

		Recipes& getRecipes() override;

		ItemAnalysis& getAnalysis() override;

	protected:
		static double refiningComponentYieldBonus(int refined_resource_tier, int refining_component_tier);
};