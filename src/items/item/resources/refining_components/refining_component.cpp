module items:refining_component;

namespace items {
	RefiningComponent::RefiningComponent(const std::string& item_name,
										 const std::string& image_path,
										 const int tier,
										 const bool buy_equals_sell,
										 const double sell_price,
										 const double buy_price) :
		Resource(item_name,
				 image_path,
				 tier,
				 buy_equals_sell,
				 sell_price,
				 buy_price) {
	}

	RefiningComponent::RefiningComponent(Json::Value json_value) :
		Resource(std::move(json_value)) {
	}

	Json::Value RefiningComponent::toJson() const {
		Json::Value json_value = membersToJson();

		json_value["item_type"] = "RefiningComponent";

		return json_value;
	}
}
