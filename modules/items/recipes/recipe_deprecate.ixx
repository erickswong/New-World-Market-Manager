export module items:recipe;

import "json/json.h";
import <unordered_map>;

namespace items {
	export class Recipe {
		std::unordered_map<std::string, int> recipe;

		public:
			Recipe() = default;
			explicit Recipe(const Json::Value& json_value);

			// Returns a json representing this object
			[[nodiscard]] Json::Value toJson() const;

			// Adds an ingredient to the recipe
			void addIngredient(const std::string& ingredient_name, const int amount);

			// Returns a const reference to the recipe
			[[nodiscard]] const std::unordered_map<std::string, int>& get() const;
	};
};
