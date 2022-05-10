#include "items/resources/refined_resources/ingots/ingots.h"

Ingots::Ingots(const std::string& item_name,
			   const bool buy_equals_sell,
               const double sell_price,
               const double buy_price,
               const double base_proc,
               const double base_craft_tax,
               Recipes* recipes,
               const std::string& image_path) {
	this->item_name = item_name;
	this->buy_equals_sell = buy_equals_sell;
	this->sell_price = sell_price;
	this->buy_price = buy_price;
	this->base_proc = base_proc;
	this->base_craft_tax = base_craft_tax;
	this->recipes = recipes;
	this->image_path = image_path;
}

double Ingots::craftTax(Settings& settings) {
	// TODO: implement craftTax
	return base_craft_tax;
}

double Ingots::proc(Recipe& recipe, Settings& settings) {
	double total_proc = base_proc;
	total_proc += settings.getTradeSkills().smeltingYieldBonus();
	total_proc += settings.getArmourSets().getSmelterSet().yieldBonus();
	total_proc += settings.getFortBonuses().yieldBonus();

	int flux_tier = 0;
	for (const auto& [ingredient_name, amount] : *recipe.getRecipe()) {
		if (ingredient_name == "Obsidian Flux") {
			flux_tier = 5;
			break;
		}
		if (ingredient_name == "Shelldust Flux") {
			flux_tier = 4;
			break;
		}
		if (ingredient_name == "Sand Flux") {
			flux_tier = 3;
			break;
		}
	}

	// Gold Ingot Anomaly
	if (item_name == "Gold Ingot") {
		if (flux_tier == 5) {
			total_proc += 0.5;
		} else if (flux_tier == 4) {
			total_proc += 0.25;
		}
	} else {
		total_proc += refiningComponentYieldBonus(tier, flux_tier);
	}

	return std::max(1.0, total_proc);
}
