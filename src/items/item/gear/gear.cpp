module items:gear;

namespace items {
	Gear::Gear(const std::string& item_name,
			   const std::string& image_path) :
		Item(item_name,
			 image_path) {
	}

	Gear::Gear(Json::Value json_value) :
		Item(json_value) {
	}

	Json::Value Gear::toJson() const {
		Json::Value json_value = Item::toJson();

		json_value["item_type"] = "Gear";

		return json_value;
	}
}