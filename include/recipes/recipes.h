#pragma once

#include <vector>
#include "recipe.h"

class Recipes {
	public:
		void addRecipe(const Recipe& recipe);

		[[nodiscard]] std::vector<Recipe> getRecipes() const;

	private:
		std::vector<Recipe> recipes;
};
