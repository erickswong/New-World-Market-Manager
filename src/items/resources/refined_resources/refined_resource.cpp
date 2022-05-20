#include <utility>

#include "items/resources/refined_resources/refined_resource.h"

RefinedResource::RefinedResource(std::string item_name,
								 std::string image_path,
								 const int tier,
								 const bool buy_equals_sell,
								 const double sell_price,
								 const double buy_price,
								 const double base_yield,
								 const double base_craft_tax,
								 const Recipes& recipes)
									 : Resource(std::move(item_name),
												std::move(image_path),
												tier, buy_equals_sell,
												sell_price,
												buy_price) {
	this->base_yield = base_yield;
	this->base_craft_tax = base_craft_tax;
	this->recipes = recipes;
}

RefinedResource::RefinedResource(Json::Value json_value)
	: Resource(json_value) {
	this->base_yield = json_value["base_yield"].asDouble();
	this->base_craft_tax = json_value["base_craft_tax"].asDouble();
	this->recipes = Recipes(json_value["recipes"]);
}

Json::Value RefinedResource::toJson() const {
	Json::Value json_value = Resource::toJson();

	json_value["item_type"] = "RefinedResource";
	json_value["base_yield"] = base_yield;
	json_value["base_craft_tax"] = base_craft_tax;
	json_value["recipes"] = recipes.toJson();

	return json_value;
}

bool RefinedResource::setBuyEqualsSell(const bool buy_equals_sell) {
	this->buy_equals_sell = buy_equals_sell;

	if (buy_equals_sell && buy_price != sell_price) {
		buy_price = sell_price;

		return true;
	}

	return false;
}

bool RefinedResource::setSellPrice(const double sell_price) {
	if (this->sell_price != sell_price) {
		this->sell_price = sell_price;

		if (buy_equals_sell) {
			buy_price = sell_price;
		}

		return true;
	}

	return false;
}

bool RefinedResource::setBuyPrice(const double buy_price) {
	if (this->buy_price != buy_price) {
		this->buy_price = buy_price;

		return true;
	}

	return false;
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
