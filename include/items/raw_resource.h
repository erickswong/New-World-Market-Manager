#pragma once

#include "resource.h"

class RawResource : public Resource {
	public:
		RawResource(bool buy_equals_sell,
					double sell_price,
					double buy_price,
					std::string image_path);
};
