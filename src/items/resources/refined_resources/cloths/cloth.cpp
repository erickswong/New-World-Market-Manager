#include <algorithm>
#include <utility>

#include "items/resources/refined_resources/cloths/cloth.h"

Cloth::Cloth(std::string item_name,
             std::string image_path,
             const int tier,
             const bool buy_equals_sell,
             const double sell_price,
             const double buy_price,
             const double base_yield,
             const double base_craft_tax,
             const Recipes& recipes)
	               : RefinedResource(std::move(item_name),
	                                 std::move(image_path),
	                                 tier,
	                                 buy_equals_sell,
	                                 sell_price,
	                                 buy_price,
	                                 base_yield,
	                                 base_craft_tax,
	                                 recipes) {
}

Cloth::Cloth(Json::Value json_value)
	: RefinedResource(std::move(json_value)) {
}

Json::Value Cloth::toJson() const {
	Json::Value json_value = RefinedResource::toJson();

	json_value["item_type"] = "Cloth";

	return json_value;
}

double Cloth::getCraftTax(Settings& settings) {
	// TODO: implement craft_tax modifiers from settings
	return base_craft_tax;
}

double Cloth::getYield(Recipe& recipe, Settings& settings) {
	// Determine the tier of the refining component in the given recipe
	int refining_component_tier = 0;
	for (const auto& [ingredient_name, amount] : recipe.getRecipe()) {
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
	const double yield = base_yield + settings.weavingYieldBonus() + refiningComponentYieldBonus(tier, refining_component_tier);

	// Return the yield
	return std::max(1., yield) * settings.fortYieldBonusMultiplier();
}
