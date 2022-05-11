#pragma once

#include <unordered_map>
#include <string>

class Recipe {
	public:
		void addIngredient(const std::string& ingredient_name, int amount);

		[[nodiscard]] std::unordered_map<std::string, int> getRecipe() const;

	private:
		std::unordered_map<std::string, int> recipe;
};
