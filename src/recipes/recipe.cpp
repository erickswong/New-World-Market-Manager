module recipes:recipe;

Recipe::Recipe() = default;

Recipe::Recipe(Json::Value json_value) {
    for (const std::string& ingredient_name : json_value.getMemberNames()) {
        const int amount = json_value[ingredient_name].asInt();

        addIngredient(ingredient_name, amount);
    }
}

Json::Value Recipe::toJson() const {
    Json::Value json_value;

    for (const auto& [ingredient_name, amount] : recipe) {
        json_value[ingredient_name] = amount;
    }

    return json_value;
}

std::unordered_map<std::string, int>& Recipe::get() {
    return recipe;
}

void Recipe::addIngredient(const std::string& ingredient_name, int amount) {
    recipe.insert({ ingredient_name, amount });
}
