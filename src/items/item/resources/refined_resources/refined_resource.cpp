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
									 const double base_craft_tax,
									 const Recipes& recipes) :
		Resource(item_name,
				 image_path,
				 tier,
				 buy_equals_sell,
				 sell_price,
				 buy_price),
		base_yield(base_yield),
		base_craft_tax(base_craft_tax),
		recipes(recipes) {
	}

	RefinedResource::RefinedResource(const Json::Value& json_value) :
		Resource(json_value),
		base_yield(json_value["base_yield"].asDouble()),
		base_craft_tax(json_value["base_craft_tax"].asDouble()),
		recipes(Recipes(json_value["recipes"])) {
	}

	Json::Value RefinedResource::toJson() const {
		Json::Value json_value = Resource::toJson();

		json_value["base_yield"]     = base_yield;
		json_value["base_craft_tax"] = base_craft_tax;
		json_value["recipes"]        = recipes.toJson();

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

	const Recipes& RefinedResource::getRecipes() const {
		return recipes;
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
	
	const Recipe& RefinedResource::getBestInstantRecipe() const {
		return best_instant_recipe;
	}

	void RefinedResource::setBestInstantRecipe(Recipe best_instant_recipe) {
		this->best_instant_recipe = best_instant_recipe;
	}
	
	const Recipe& RefinedResource::getBestRecipe() const {
		return best_recipe;
	}

	void RefinedResource::setBestRecipe(Recipe best_recipe) {
		this->best_recipe = best_recipe;
	}

	double RefinedResource::refiningComponentYieldBonus(const int refined_resource_tier, const int refining_component_tier) {
		switch (refined_resource_tier) {
			case 3:
				switch (refining_component_tier) {
					case 4:
						return 0.5;
					case 5:
						return 0.75;
					default:
						return 0.;
				}
			case 4:
				switch (refining_component_tier) {
					case 3:
						return -0.05;
					case 5:
						return 0.25;
					default:
						return 0.;
				}
			case 5:
				switch (refining_component_tier) {
					case 3:
						return -0.1;
					case 4:
						return -0.05;
					default:
						return 0.;
				}
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
