export module items:ingot;

import recipe_book;

import :refined_resource;

namespace items {
	export class Ingot final : public RefinedResource {
		public:
			Ingot(const std::string& item_name,
				  int tier,
				  bool buy_equals_sell,
				  double sell_price,
				  double buy_price,
				  double base_yield,
				  double base_craft_tax);
			explicit Ingot(const Json::Value& json_value);

			// Returns a json representing this object
			[[nodiscard]] Json::Value toJson() const override;

			// Returns the craft tax
			double craftTax() const override;

			// Returns the yield
			double yield() const override;
	};
};
