#include "items/resources/refined_resources/blocks/blocks.h"

Blocks::Blocks(const std::string& item_name,
			   int tier,
               bool buy_equals_sell,
               double sell_price,
               double buy_price,
               double base_yield,
               double base_craft_tax,
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

double Blocks::getCraftTax(Settings& settings) {
	// TODO: implement craft_tax modifiers from settings
	return base_craft_tax;
}

double Blocks::getYield(Recipe& recipe, Settings& settings) {
	// Determine the tier of the refining component in the given recipe
	int refining_component_tier = 0;
	for (const auto& [ingredient_name, amount] : *recipe.getRecipe()) {
		if (ingredient_name == "Obsidian Sandpaper") {
			refining_component_tier = 5;
			break;
		}
		if (ingredient_name == "Fine Sandpaper") {
			refining_component_tier = 4;
			break;
		}
		if (ingredient_name == "Coarse Sandpaper") {
			refining_component_tier = 3;
			break;
		}
	}

	// Calculate the yield
	const double yield = base_yield + settings.stonecuttingYieldBonus() + refiningComponentYieldBonus(tier, refining_component_tier);

	// Return the yield
	return std::max(1.0, yield);
}
