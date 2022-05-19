#include <algorithm>
#include <utility>

#include "items/resources/refined_resources/leathers/leathers.h"

Leathers::Leathers(std::string item_name,
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

double Leathers::getCraftTax(Settings& settings) {
	// TODO: implement craft_tax modifiers from settings
	return base_craft_tax;
}

double Leathers::getYield(Recipe& recipe, Settings& settings) {
	// Determine the tier of the refining component in the given recipe
	int refining_component_tier = 0;
	for (const auto& [ingredient_name, amount] : recipe.getRecipe()) {
		if (ingredient_name == "Aged Tannin") {
			refining_component_tier = 5;
			break;
		}
		if (ingredient_name == "Rested Tannin") {
			refining_component_tier = 4;
			break;
		}
		if (ingredient_name == "Tannin") {
			refining_component_tier = 3;
			break;
		}
	}

	// Calculate the yield
	const double yield = base_yield + settings.leatherworkingYieldBonus() + refiningComponentYieldBonus(tier, refining_component_tier);

	// Return the yield
	return std::max(1., yield);
}
