#pragma once

#include <vector>
#include "recipe.h"

class Recipes {
	public:
		Recipes();
		explicit Recipes(const Json::Value& json_value);

		[[nodiscard]] Json::Value toJson() const;
		
		void addRecipe(const Recipe& recipe);

		[[nodiscard]] std::vector<Recipe> getRecipes() const;

	private:
		std::vector<Recipe> recipes;
};
