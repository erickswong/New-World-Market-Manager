#include <algorithm>

#include "items/resources/refined_resources/leathers/leathers.h"

Leathers::Leathers(const std::string& item_name,
				   const int tier,
				   const bool buy_equals_sell,
				   const float sell_price,
				   const float buy_price,
				   const float base_yield,
				   const float base_craft_tax,
				   const Recipes recipes,
                   const std::string& image_path) {
	this->item_name = item_name;
	this->tier = tier;
	this->buy_equals_sell = buy_equals_sell;
	this->sell_price = sell_price;
	this->buy_price = buy_price;
	this->base_yield = base_yield;
	this->base_craft_tax = base_craft_tax;
	this->recipes = recipes;
	this->image_path = image_path;
}

float Leathers::getCraftTax(Settings& settings) {
	// TODO: implement craft_tax modifiers from settings
	return base_craft_tax;
}

float Leathers::getYield(Recipe& recipe, Settings& settings) {
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
	const float yield = base_yield + settings.leatherworkingYieldBonus() + refiningComponentYieldBonus(tier, refining_component_tier);

	// Return the yield
	return std::max(1.0f, yield);
}
