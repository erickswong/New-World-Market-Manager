#pragma once

#include "resource.h"

class RefiningComponent final : public Resource {
	public:
		RefiningComponent(bool buy_equals_sell,
						  double sell_price,
						  double buy_price,
						  std::string image_path);
};
