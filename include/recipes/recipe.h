#pragma once

#include <map>
#include <string>

class Recipe {
	public:
		Recipe();
		~Recipe();

		void addIngredient(const std::string& ingredient_name, int amount) const;

		[[nodiscard]] std::map<std::string, int>* getRecipe() const;

	private:
		std::map<std::string, int>* recipe;
};
