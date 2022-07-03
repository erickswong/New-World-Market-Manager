module items:gear;

namespace items {
	Gear::Gear(const std::string& item_name) :
		Item(item_name) {
	}

	Gear::Gear(const Json::Value& json_value) :
		Item(json_value) {
	}

	Json::Value Gear::toJson() const {
		Json::Value json_value = Item::toJson();

		json_value["item_type"] = "Gear";

		return json_value;
	}
}