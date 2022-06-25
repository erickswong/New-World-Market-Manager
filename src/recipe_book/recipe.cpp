module recipe_book:recipe;

namespace recipe_book {
    Recipe::Recipe(const std::string& item_name) :
        item_name(item_name) {
    }

    Recipe::Recipe(const std::string& item_name, const Json::Value& json_value) :
        item_name(item_name) {

        for (const std::string& ingredient_name : json_value.getMemberNames()) {
            const int amount = json_value[ingredient_name].asInt();

            addIngredient(ingredient_name, amount);
        }
	}

    Json::Value Recipe::toJson() const {
        Json::Value json_value;

        for (const auto& [ingredient_name, amount] : ingredients) {
            json_value[ingredient_name] = amount;
        }

        return json_value;
    }

    Recipe& Recipe::addIngredient(const std::string& ingredient_name, const int amount) {
        ingredients.insert({ ingredient_name, amount });

        return *this;
    }

    std::string Recipe::getItemName() const {
        return item_name;
    }

    const std::unordered_map<std::string, int>& Recipe::getIngredients() const {
        return ingredients;
    }
}