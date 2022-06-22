export module items:leather;

import :refined_resource;

namespace items {
	export class Leather final : public RefinedResource {
		public:
			Leather(const std::string& item_name,
					const std::string& image_path,
					int tier,
					bool buy_equals_sell,
					double sell_price,
					double buy_price,
					double base_yield,
					double base_craft_tax,
					const Recipes& recipes);
			explicit Leather(const Json::Value& json_value);

			// Returns a json representing this object
			[[nodiscard]] Json::Value toJson() const override;

			// Returns the craft tax
			double craftTax() const override;

			// Returns the yield when using the given recipe
			double yield(const Recipe& recipe) const override;
	};
};
