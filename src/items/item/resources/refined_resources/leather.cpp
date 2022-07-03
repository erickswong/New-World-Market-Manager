module items:leather;

import settings;

namespace items {
	Leather::Leather(const std::string& item_name,
					 const int tier,
					 const bool buy_equals_sell,
					 const double sell_price,
					 const double buy_price,
					 const double base_yield,
					 const double base_craft_tax) :
		RefinedResource(item_name,
						tier,
						buy_equals_sell,
						sell_price,
						buy_price,
						base_yield,
						base_craft_tax) {
	}

	Leather::Leather(const Json::Value& json_value) :
		RefinedResource(json_value) {
	}

	Json::Value Leather::toJson() const {
		Json::Value json_value = RefinedResource::toJson();

		json_value["item_type"] = "Leather";

		return json_value;
	}

	double Leather::craftTax() const {
		// TODO: implement craft_tax modifiers from settings
		return getBaseCraftTax();
	}

	double Leather::yield() const {
		// Calculate the yield
		const double yield = getBaseYield() + refiningComponentYieldBonus(getTier()) + settings::leatherworkingYieldBonus();

		// Return the yield
		return std::max(1., yield);
	}
}
