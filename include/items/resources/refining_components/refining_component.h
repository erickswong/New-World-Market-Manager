#pragma once

#include "items/resources/resource.h"

class RefiningComponent final : public Resource {
	public:
		RefiningComponent(std::string item_name,
						  std::string image_path,
						  int tier,
						  bool buy_equals_sell,
						  double sell_price,
						  double buy_price);
		explicit RefiningComponent(Json::Value json_value);

		[[nodiscard]] Json::Value toJson() const override;
};
