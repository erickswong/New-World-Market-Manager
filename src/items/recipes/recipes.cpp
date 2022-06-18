module items:recipes;

namespace items {
    Recipes::Recipes(const Json::Value& json_value) {
        for (const Json::Value& recipe_json_value : json_value) {
            addRecipe(Recipe(recipe_json_value));
        }
    }

    Json::Value Recipes::toJson() const {
        Json::Value json_value;

        for (const Recipe& recipe : recipes) {
            json_value.append(recipe.toJson());
        }

        return json_value;
    }

    void Recipes::addRecipe(const Recipe& recipe) {
        recipes.push_back(recipe);
    }

    std::vector<Recipe>& Recipes::get() {
        return recipes;
    }
}
