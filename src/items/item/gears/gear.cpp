module items:gear;

namespace items {
	Gear::Gear(const std::string& item_name,
			   const bool acquired) :
		Item(item_name),
	    acquired(acquired) {
	}

	Gear::Gear(const Json::Value& json_value) :
		Item(json_value),
		acquired(json_value["acquired"].asBool()) {
	}

	Json::Value Gear::toJson() const {
		Json::Value json_value = Item::toJson();

		json_value["acquired"] = acquired;

		return json_value;
	}

	bool Gear::getAcquired() const {
		return acquired;
	}

	void Gear::setAcquired(bool acquired) {
		this->acquired = acquired;
	}
}