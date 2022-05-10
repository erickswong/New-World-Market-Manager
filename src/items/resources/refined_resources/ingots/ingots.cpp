#include "items/resources/refined_resources/ingots/ingots.h"

Ingots::Ingots(const std::string& item_name,
			   int tier,
			   const bool buy_equals_sell,
               const double sell_price,
               const double buy_price,
               const double base_yield,
               const double base_craft_tax,
               Recipes* recipes,
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

double Ingots::getCraftTax(Settings& settings) {
	// TODO: implement craft_tax modifiers from settings
	return base_craft_tax;
}

double Ingots::getYield(Recipe& recipe, Settings& settings) {
	double yield = base_yield + settings.smeltingYieldBonus();

	// Determine the tier of the refining component in the given recipe
	int refining_component_tier = 0;
	for (const auto& [ingredient_name, amount] : *recipe.getRecipe()) {
		if (ingredient_name == "Obsidian Flux") {
			refining_component_tier = 5;
			break;
		}
		if (ingredient_name == "Shelldust Flux") {
			refining_component_tier = 4;
			break;
		}
		if (ingredient_name == "Sand Flux") {
			refining_component_tier = 3;
			break;
		}
	}

	// Gold Ingot Anomaly
	if (item_name == "Gold Ingot") {
		if (refining_component_tier == 5) {
			yield += 0.5;
		} else if (refining_component_tier == 4) {
			yield += 0.25;
		}
	} else {
		yield += refiningComponentYieldBonus(tier, refining_component_tier);
	}

	// Return the yield
	return std::max(1.0, yield);
}
