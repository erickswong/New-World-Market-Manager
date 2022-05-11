#pragma once

#include "items/resources/resource.h"

class RawResource final : public Resource {
	public:
		RawResource(const std::string& item_name,
					int tier,
					bool buy_equals_sell,
					float sell_price,
					float buy_price,
					const std::string& image_path);
};
