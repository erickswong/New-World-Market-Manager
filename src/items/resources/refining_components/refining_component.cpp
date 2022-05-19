#include "items/resources/refining_components/refining_component.h"

RefiningComponent::RefiningComponent(std::string item_name,
									 std::string image_path,
									 const int tier,
									 const bool buy_equals_sell,
									 const double sell_price,
									 const double buy_price)
	                                     : Resource(std::move(item_name),
			                                        std::move(image_path),
													tier,
													buy_equals_sell,
													sell_price,
													buy_price) {
}
