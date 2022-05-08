#include "items/recipes.h"

Recipes::Recipes() : recipes(new std::vector<Recipe>) {
}

Recipes::~Recipes() {
	delete recipes;
}

void Recipes::addRecipe(const Recipe& recipe) const {
	recipes->push_back(recipe);
}

std::vector<Recipe>* Recipes::getRecipes() const {
	return recipes;
}
