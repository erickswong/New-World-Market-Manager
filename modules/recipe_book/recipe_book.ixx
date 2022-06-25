export module recipe_book;

export import :recipe;

import "json/json.h";
import <unordered_map>;

namespace recipe_book {
	using RecipeBook = std::unordered_multimap<std::string, Recipe>;
	using RecipeRange = std::pair<RecipeBook::const_iterator, RecipeBook::const_iterator>;

	RecipeBook recipe_book;

	// Set up recipe_book
	export void setUp();
	// Resets members to default values
	export void reset() noexcept;

	// Sets members to values from json
	export void fromJson(const Json::Value& json_value);
	// Returns a json representing recipe_book
	export [[nodiscard]] Json::Value toJson();
	// Writes a json representing this namespace to disk
	export void writeToDisk();

	// Adds a recipe
	export void addRecipe(const Recipe& recipe);

	// Returns a pair of two const_iterators representing the range containing all Recipes with item_name
	export [[nodiscard]] RecipeRange recipeRange(const std::string& item_name);
};
