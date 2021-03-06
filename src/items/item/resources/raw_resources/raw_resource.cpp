module items:raw_resource;

namespace items {
	RawResource::RawResource(const std::string& item_name,
							 const int tier,
							 const bool buy_equals_sell,
							 const double sell_price,
							 const double buy_price) :
		Resource(item_name,
				 tier,
				 buy_equals_sell,
				 sell_price,
				 buy_price) {
	}

	RawResource::RawResource(const Json::Value& json_value) :
		Resource(json_value) {
	}

	Json::Value RawResource::toJson() const {
		Json::Value json_value = Resource::toJson();

		json_value["item_type"] = "RawResource";

		return json_value;
	}
}
