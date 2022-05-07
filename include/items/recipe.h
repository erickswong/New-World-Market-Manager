#pragma once

#include <map>
#include <string>

class Recipe {
	public:
		Recipe();
		~Recipe();

		std::map<std::string, int>* getRecipe();
		void addIngredient(std::string ingredient_name, int amount);

	private:
		std::map<std::string, int>* recipe;
};
