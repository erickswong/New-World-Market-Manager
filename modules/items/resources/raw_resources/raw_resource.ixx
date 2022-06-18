export module items:raw_resource;

import :resource;

namespace items {
	export class RawResource final : public Resource {
		public:
			RawResource(std::string item_name,
						std::string image_path,
						int tier,
						bool buy_equals_sell,
						double sell_price,
						double buy_price);
			explicit RawResource(Json::Value json_value);

			[[nodiscard]] Json::Value toJson() const override;
	};
};
