export module items:raw_resource;

import :resource;

namespace items {
	export class RawResource final : public Resource {
		public:
			RawResource(const std::string& item_name,
						const std::string& image_path,
						int tier,
						bool buy_equals_sell,
						double sell_price,
						double buy_price);
			explicit RawResource(const Json::Value& json_value);

			// Returns a json representing this object
			[[nodiscard]] Json::Value toJson() const override;
	};
};
