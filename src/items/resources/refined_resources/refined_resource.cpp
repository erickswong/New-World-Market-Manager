#include "items/resources/refined_resources/refined_resource.h"

RefinedResource::RefinedResource() = default;

bool RefinedResource::setBuyEqualsSell(const bool buy_equals_sell) {
	this->buy_equals_sell = buy_equals_sell;

	if (buy_equals_sell && buy_price != sell_price) {
		buy_price = sell_price;

		return true;
	}

	return false;
}

bool RefinedResource::setSellPrice(const float sell_price) {
	if (this->sell_price != sell_price) {
		this->sell_price = sell_price;

		if (buy_equals_sell) {
			buy_price = sell_price;
		}

		return true;
	}

	return false;
}

bool RefinedResource::setBuyPrice(const float buy_price) {
	if (this->buy_price != buy_price) {
		this->buy_price = buy_price;

		return true;
	}

	return false;
}

float RefinedResource::getBaseYield() {
	return base_yield;
}

float RefinedResource::getBaseCraftTax() {
	return base_craft_tax;
}

Recipes& RefinedResource::getRecipes() {
	return recipes;
}

ItemAnalysis& RefinedResource::getAnalysis() {
	return analysis;
}

float RefinedResource::refiningComponentYieldBonus(const int refined_resource_tier, const int refining_component_tier) {
	switch (refined_resource_tier) {
		case 3:
			switch (refining_component_tier) {
				case 4:
					return 0.5f;
				case 5:
					return 0.75f;
				default:
					return 0.0f;
			}
		case 4:
			switch (refining_component_tier) {
				case 3:
					return -0.05f;
				case 5:
					return 0.25f;
				default:
					return 0.0f;
			}
		case 5:
			switch (refining_component_tier) {
				case 3:
					return -0.1f;
				case 4:
					return -0.05f;
				default:
					return 0.0f;
			}
		default:
			return 0.0f;
	}
}
