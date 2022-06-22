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

	RefinedResource::RefinedResource(Json::Value json_value) :
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

	double RefinedResource::bestInstantAcquireCost() {
		return std::min(getSellPrice(), analysis.best_instant_craft_cost);
	}

	double RefinedResource::bestAcquireCost() {
		return std::min({ getSellPrice(), analysis.best_instant_craft_cost, analysis.best_craft_cost, getBuyPrice() });
	}

	double RefinedResource::getBaseYield() {
		return base_yield;
	}

	double RefinedResource::getBaseCraftTax() {
		return base_craft_tax;
	}

	Recipes& RefinedResource::getRecipes() {
		return recipes;
	}

	ItemAnalysis& RefinedResource::getAnalysis() {
		return analysis;
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
}
