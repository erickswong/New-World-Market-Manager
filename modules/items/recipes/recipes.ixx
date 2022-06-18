export module items:recipes;

export import :recipe;

import "json/json.h";

namespace items {
	export class Recipes {
		public:
			// Default constructor
			Recipes() = default;
			// Constructs the recipes represented by the json
			explicit Recipes(const Json::Value& json_value);

			// Returns a json representing this object
			[[nodiscard]] Json::Value toJson() const;

			// Adds a recipe to recipes
			void addRecipe(const Recipe& recipe);

			// Returns a reference to recipes
			[[nodiscard]] std::vector<Recipe>& get();

		private:
			std::vector<Recipe> recipes;
	};
};
