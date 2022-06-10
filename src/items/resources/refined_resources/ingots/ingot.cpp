module items:ingot;

Ingot::Ingot(std::string item_name,
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

Ingot::Ingot(Json::Value json_value)
	: RefinedResource(std::move(json_value)) {
}

Json::Value Ingot::toJson() const {
	Json::Value json_value = RefinedResource::toJson();

	json_value["item_type"] = "Ingot";

	return json_value;
}

double Ingot::getCraftTax(Settings* settings) {
	// TODO: implement craft_tax modifiers from settings
	return base_craft_tax;
}

double Ingot::getYield(Recipe& recipe, Settings* settings) {
	double yield = base_yield + settings->smeltingYieldBonus();

	// Determine the tier of the refining component in the given recipe
	int refining_component_tier = 0;
	for (const auto& [ingredient_name, amount] : recipe.get()) {
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
	return std::max(1., yield) * settings->fortYieldBonusMultiplier();
}
