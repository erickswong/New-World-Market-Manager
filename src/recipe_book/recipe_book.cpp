module recipe_book;

import exceptions;
import std.core;
import std.filesystem;

import :default_recipe_book;

namespace recipe_book {
	void setUp() {
		try {
			// Open file for reading
			std::ifstream file("data/recipe_book.json");
			Json::Reader reader;
			Json::Value json_value;

			// Read file into json_value
			if (!reader.parse(file, json_value)) {
				throw BadJsonException("Unable to parse recipe_book.json");
			}

			// Set members to values from json
			fromJson(json_value);
		} catch (const std::exception&) {
			// Reset members to default values
			default_recipe_book::setUp();

			// TODO: alert that creating items from json was unsuccessful with message e.what()
		}
	}

	void reset() noexcept {
		recipe_book.clear();
	}

	void fromJson(const Json::Value& json_value) {
		try {
			reset();

			for (const std::string& item_name : json_value.getMemberNames()) {
				for (const auto& recipe_json_value : json_value[item_name]) {
					addRecipe(Recipe(item_name, recipe_json_value));
				}
			}
		} catch (const std::exception& e) {
			throw BadJsonException("recipe_book is malformed", e);
		}
	}

	Json::Value toJson() {
		Json::Value json_value;

		for (const auto& [item_name, recipe] : recipe_book) {
			json_value[item_name].append(recipe.toJson());
		}

		return json_value;
	}

	void writeToDisk() {
		// Create data directory if missing
		std::filesystem::create_directory("data");

		// Create recipe_book.json file
		std::ofstream file("data/recipe_book.json");

		// Write json into file
		Json::StyledWriter styled_writer;
		file << styled_writer.write(toJson());
	}

	void addRecipe(const Recipe& recipe) {
		recipe_book.insert({ recipe.getItemName(), recipe });
	}

	RecipeRange recipeRange(const std::string& item_name) {
		return std::as_const(recipe_book).equal_range(item_name);
	}
}
