export module recipes:recipe;

import "json/json.h";
import <unordered_map>;

export class Recipe {
	public:
		Recipe();
		explicit Recipe(Json::Value json_value);

		[[nodiscard]] Json::Value toJson() const;

		[[nodiscard]] std::unordered_map<std::string, int>& get();

		void addIngredient(const std::string& ingredient_name, int amount);

	private:
		std::unordered_map<std::string, int> recipe;
};
