export module items:refining_component;

import :resource;

namespace items {
	export class RefiningComponent final : public Resource {
		public:
			RefiningComponent(const std::string& item_name,
							  const std::string& image_path,
							  int tier,
							  bool buy_equals_sell,
							  double sell_price,
							  double buy_price);
			explicit RefiningComponent(Json::Value json_value);

			// Returns a json representing this object
			[[nodiscard]] Json::Value toJson() const override;
	};
};
