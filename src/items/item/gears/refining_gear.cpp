module items:refining_gear;

namespace items {
	RefiningGear::RefiningGear(const std::string& item_name,
							   bool acquired,
							   double yield_bonus) :
		Gear(item_name,
			 acquired),
		yield_bonus(yield_bonus) {
	}

	RefiningGear::RefiningGear(const Json::Value& json_value) :
		Gear(json_value),
		yield_bonus(json_value["yield_bonus"].asDouble()) {
	}

	Json::Value RefiningGear::toJson() const {
		Json::Value json_value = Gear::toJson();

		json_value["item_type"]   = "RefiningGear";
		json_value["yield_bonus"] = yield_bonus;

		return json_value;
	}

	double RefiningGear::yieldBonus() const {
		return getAcquired() * yield_bonus;
	}
}
