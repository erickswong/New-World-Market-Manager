#include "items/recipes.h"

Recipes::Recipes() {
	recipes = new std::vector<Recipe>();
}

Recipes::~Recipes() {
	delete recipes;
}

std::vector<Recipe>* Recipes::getRecipes() {
	return recipes;
}

void Recipes::addRecipe(Recipe recipe) {
	recipes->push_back(recipe);
}
