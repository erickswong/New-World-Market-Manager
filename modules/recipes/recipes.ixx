export module recipes;

export import :recipe;

import "json/json.h";

export class Recipes {
	public:
		Recipes();
		explicit Recipes(const Json::Value& json_value);

		[[nodiscard]] Json::Value toJson() const;

		[[nodiscard]] std::vector<Recipe>& get();

		void addRecipe(const Recipe& recipe);

	private:
		std::vector<Recipe> recipes;
};
