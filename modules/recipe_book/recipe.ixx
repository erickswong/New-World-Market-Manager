export module recipe_book:recipe;

import "json/json.h";
import <unordered_map>;

namespace recipe_book {
    export class Recipe {
        std::string item_name;                            // Item name that this recipe is for
        std::unordered_map<std::string, int> ingredients; // A mapping of the ingredient name to the amount needed

        public:
            explicit Recipe(const std::string& item_name);
            Recipe(const std::string& item_name, const Json::Value& json_value);

            // Returns a json representing this object
            [[nodiscard]] Json::Value toJson() const;

            // Adds an ingredient and returns this object by reference (for easy addIngredient chain)
            Recipe& addIngredient(const std::string& ingredient_name, const int amount);

            // Returns item_name
            [[nodiscard]] std::string getItemName() const;

            // Returns a const reference to ingredients
            [[nodiscard]] const std::unordered_map<std::string, int>& getIngredients() const;
    };
};
