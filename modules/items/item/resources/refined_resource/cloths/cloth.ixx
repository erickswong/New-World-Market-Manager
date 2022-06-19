export module items:cloth;

import :refined_resource;

namespace items {
	export class Cloth final : public RefinedResource {
		public:
			Cloth(const std::string& item_name,
				  const std::string& image_path,
				  int tier,
				  bool buy_equals_sell,
				  double sell_price,
				  double buy_price,
				  double base_yield,
				  double base_craft_tax,
				  const Recipes& recipes);
			explicit Cloth(Json::Value json_value);

			/**
			 * @brief Returns a json representing this object
			 * 
			 * @return The json
			 */
			[[nodiscard]] Json::Value toJson() const override;

			double getCraftTax() override;

			double getYield(Recipe& recipe) override;
	};
};
