export module items:leather;

import :refined_resource;

namespace items {
	export class Leather final : public RefinedResource {
		public:
			Leather(std::string item_name,
					std::string image_path,
					int tier,
					bool buy_equals_sell,
					double sell_price,
					double buy_price,
					double base_yield,
					double base_craft_tax,
					const Recipes& recipes);
			explicit Leather(Json::Value json_value);

			[[nodiscard]] Json::Value toJson() const override;

			double getCraftTax() override;

			double getYield(Recipe& recipe) override;
	};
};
