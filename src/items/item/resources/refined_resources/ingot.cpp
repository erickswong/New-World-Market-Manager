module items:ingot;

import settings;

namespace items {
	Ingot::Ingot(const std::string& item_name,
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

	Ingot::Ingot(const Json::Value& json_value) :
		RefinedResource(json_value) {
	}

	Json::Value Ingot::toJson() const {
		Json::Value json_value = RefinedResource::toJson();

		json_value["item_type"] = "Ingot";

		return json_value;
	}

	double Ingot::craftTax() const {
		// TODO: implement craft_tax modifiers from settings
		return getBaseCraftTax();
	}

	double Ingot::yield() const {
		// Calculate the yield
		const double yield = getBaseYield() + refiningComponentYieldBonus(getTier()) + settings::smeltingYieldBonus();

		// Return the yield
		return std::max(1., yield);
	}
}
