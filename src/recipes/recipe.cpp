#include "recipes/recipe.h"

void Recipe::addIngredient(const std::string& ingredient_name, int amount) {
	recipe.insert({ ingredient_name, amount });
}

std::unordered_map<std::string, int> Recipe::getRecipe() const {
	return recipe;
}
