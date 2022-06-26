module items:refined_resource;

import std.core;
namespace items {
	RefinedResource::RefinedResource(const std::string& item_name,
									 const std::string& image_path,
									 const int tier,
									 const bool buy_equals_sell,
									 const double sell_price,
									 const double buy_price,
									 const double base_yield,
									 const double base_craft_tax) :
		Resource(item_name,
				 image_path,
				 tier,
				 buy_equals_sell,
				 sell_price,
				 buy_price),
		base_yield(base_yield),
		base_craft_tax(base_craft_tax),
		best_instant_recipe(recipe_book::Recipe(item_name)),
		best_recipe(recipe_book::Recipe(item_name)) {
	}

	RefinedResource::RefinedResource(const Json::Value& json_value) :
		Resource(json_value),
		base_yield(json_value["base_yield"].asDouble()),
		base_craft_tax(json_value["base_craft_tax"].asDouble()),
		best_instant_recipe(recipe_book::Recipe(getItemName())),
		best_recipe(recipe_book::Recipe(getItemName())) {
	}

	Json::Value RefinedResource::toJson() const {
		Json::Value json_value = Resource::toJson();

		json_value["base_yield"]     = base_yield;
		json_value["base_craft_tax"] = base_craft_tax;

		return json_value;
	}

	double RefinedResource::bestInstantAcquireCost() const {
		return std::min(getSellPrice(), best_instant_craft_cost);
	}

	double RefinedResource::bestAcquireCost() const {
		return std::min({ getSellPrice(), best_instant_craft_cost, best_craft_cost, getBuyPrice() });
	}

	double RefinedResource::bestInstantMargin() const {
		return margin(getSellPrice(), best_instant_craft_cost);
	}

	double RefinedResource::bestMargin() const {
		return margin(getSellPrice(), best_craft_cost);
	}

	double RefinedResource::bestInstantMarkup() const {
		return markup(getSellPrice(), best_instant_craft_cost);
	}

	double RefinedResource::bestMarkup() const {
		return markup(getSellPrice(), best_craft_cost);
	}

	double RefinedResource::getBaseYield() const {
		return base_yield;
	}

	double RefinedResource::getBaseCraftTax() const {
		return base_craft_tax;
	}
	
	double RefinedResource::getBestInstantCraftCost() const {
		return best_instant_craft_cost;
	}

	void RefinedResource::setBestInstantCraftCost(double best_instant_craft_cost) {
		this->best_instant_craft_cost = best_instant_craft_cost;
	}
	
	double RefinedResource::getBestCraftCost() const {
		return best_craft_cost;
	}

	void RefinedResource::setBestCraftCost(double best_craft_cost) {
		this->best_craft_cost = best_craft_cost;
	}
	
	const recipe_book::Recipe& RefinedResource::getBestInstantRecipe() const {
		return best_instant_recipe;
	}

	void RefinedResource::setBestInstantRecipe(recipe_book::Recipe best_instant_recipe) {
		this->best_instant_recipe = best_instant_recipe;
	}
	
	const recipe_book::Recipe& RefinedResource::getBestRecipe() const {
		return best_recipe;
	}

	void RefinedResource::setBestRecipe(recipe_book::Recipe best_recipe) {
		this->best_recipe = best_recipe;
	}

	double RefinedResource::refiningComponentYieldBonus(const int refined_resource_tier) const {
		// Gold Ingot Anomaly
		if (getItemName() == "Gold Ingot") {
			return 0.5;
		}

		// Determine yield bonus from refined_resource_tier
		switch (refined_resource_tier) {
			case 3:
				return 0.75;
			case 4:
				return 0.25;
			default:
				return 0.;
		}
	}

	double RefinedResource::margin(const double sell_price, const double acquire_cost) {
		return (sell_price - acquire_cost) / sell_price;
	}

	double RefinedResource::markup(const double sell_price, const double acquire_cost) {
		return (sell_price - acquire_cost) / acquire_cost;
	}
}
