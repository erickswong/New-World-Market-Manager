export module items:gear;

import :item;

namespace items {
	export class Gear final : public Item {
		public:
			Gear(const std::string& item_name,
				 const std::string& image_path);
			explicit Gear(Json::Value json_value);

			// Returns a json representing this object
			[[nodiscard]] Json::Value toJson() const override;
	};
}