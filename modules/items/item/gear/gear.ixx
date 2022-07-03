export module items:gear;

import :item;

namespace items {
	export class Gear final : public Item {
		public:
			explicit Gear(const std::string& item_name);
			explicit Gear(const Json::Value& json_value);

			// Returns a json representing this object
			[[nodiscard]] Json::Value toJson() const override;
	};
}