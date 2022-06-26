module items:cloth;

import settings;

namespace items {
	Cloth::Cloth(const std::string& item_name,
				 const std::string& image_path,
				 const int tier,
				 const bool buy_equals_sell,
				 const double sell_price,
				 const double buy_price,
				 const double base_yield,
				 const double base_craft_tax) :
		RefinedResource(item_name,
						image_path,
						tier,
						buy_equals_sell,
						sell_price,
						buy_price,
						base_yield,
						base_craft_tax) {
	}

	Cloth::Cloth(const Json::Value& json_value) :
		RefinedResource(json_value) {
	}

	Json::Value Cloth::toJson() const {
		Json::Value json_value = RefinedResource::toJson();

		json_value["item_type"] = "Cloth";

		return json_value;
	}

	double Cloth::craftTax() const {
		// TODO: implement craft_tax modifiers from settings
		return getBaseCraftTax();
	}

	double Cloth::yield() const {
		// Calculate the yield
		const double yield = getBaseYield() + refiningComponentYieldBonus(getTier()) + settings::weavingYieldBonus();

		// Return the yield
		return std::max(1., yield);
	}
}
