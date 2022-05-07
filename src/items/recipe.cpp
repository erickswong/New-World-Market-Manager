#include "items/recipe.h"

Recipe::Recipe() {
	recipe = new std::map<std::string, int>();
}

Recipe::~Recipe() {
	delete recipe;
}

std::map<std::string, int>* Recipe::getRecipe() {
	return recipe;
}

void Recipe::addIngredient(std::string ingredient_name, int amount) {
	recipe->insert({ ingredient_name, amount });
}
