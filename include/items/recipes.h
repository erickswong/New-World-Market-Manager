#pragma once

#include <vector>
#include "recipe.h"

class Recipes {
	public:
		Recipes();
		~Recipes();

		void addRecipe(const Recipe& recipe) const;

		[[nodiscard]] std::vector<Recipe>* getRecipes() const;

	private:
		std::vector<Recipe>* recipes;
};

