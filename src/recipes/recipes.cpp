#include "recipes/recipes.h"

void Recipes::addRecipe(const Recipe& recipe) {
	recipes.push_back(recipe);
}

std::vector<Recipe> Recipes::getRecipes() const {
	return recipes;
}
