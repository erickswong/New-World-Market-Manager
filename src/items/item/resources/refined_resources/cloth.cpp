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
				 const double base_craft_tax,
				 const Recipes& recipes) :
		RefinedResource(item_name,
						image_path,
						tier,
						buy_equals_sell,
						sell_price,
						buy_price,
						base_yield,
						base_craft_tax,
						recipes) {
	}

	Cloth::Cloth(const Json::Value& json_value) :
		RefinedResource(json_value) {
	}

	Json::Value Cloth::toJson() const {
		Json::Value json_value = RefinedResource::toJson();

		json_value["item_type"] = "Cloth";

		return json_value;
	}

	double Cloth::craftTax() {
		// TODO: implement craft_tax modifiers from settings
		return getBaseCraftTax();
	}

	double Cloth::yield(Recipe& recipe) {
		// Determine the tier of the refining component in the given recipe
		int refining_component_tier = 0;
		for (const auto& [ingredient_name, amount] : recipe.get()) {
			if (ingredient_name == "Wireweave") {
				refining_component_tier = 5;
				break;
			}
			if (ingredient_name == "Silkweave") {
				refining_component_tier = 4;
				break;
			}
			if (ingredient_name == "Crossweave") {
				refining_component_tier = 3;
				break;
			}
		}

		// Calculate the yield
		const double yield = getBaseYield() + settings::weavingYieldBonus() + refiningComponentYieldBonus(getTier(), refining_component_tier);

		// Return the yield
		return std::max(1., yield) * settings::fortYieldBonusMultiplier();
	}
}
