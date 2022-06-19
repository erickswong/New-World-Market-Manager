export module items:gear;

import :item;

namespace items {
	export class Gear final : public Item {
		public:
			Gear(const std::string& item_name,
				 const std::string& image_path);
			explicit Gear(Json::Value json_value);

			/**
			 * @brief Returns a json representing this object
			 * 
			 * @return The json
			 */
			[[nodiscard]] Json::Value toJson() const override;
	};
}