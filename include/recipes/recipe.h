#pragma once

#include <unordered_map>
#include <string>

#include "jsoncpp/json/json.h"

class Recipe {
	public:
		Recipe();
		explicit Recipe(Json::Value json_value);

		[[nodiscard]] Json::Value toJson() const;

		void addIngredient(const std::string& ingredient_name, int amount);

		[[nodiscard]] std::unordered_map<std::string, int> getRecipe() const;

	private:
		std::unordered_map<std::string, int> recipe;
};
