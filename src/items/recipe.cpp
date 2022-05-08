#include "items/recipe.h"

Recipe::Recipe() : recipe(new std::map<std::string, int>) {
}

Recipe::~Recipe() {
	delete recipe;
}

void Recipe::addIngredient(const std::string& ingredient_name, int amount) const {
	recipe->insert({ ingredient_name, amount });
}

std::map<std::string, int>* Recipe::getRecipe() const {
	return recipe;
}
