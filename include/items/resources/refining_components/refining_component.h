#pragma once

#include "items/resources/resource.h"

class RefiningComponent final : public Resource {
	public:
		RefiningComponent(const std::string& item_name,
						  int tier,
						  bool buy_equals_sell,
						  double sell_price,
						  double buy_price,
						  const std::string& image_path);
};
