#pragma once

#include <vector>
#include "recipe.h"

class Recipes {
	public:
		Recipes();
		~Recipes();

		std::vector<Recipe>* getRecipes();
		void addRecipe(Recipe recipe);
	private:
		std::vector<Recipe>* recipes;
};

