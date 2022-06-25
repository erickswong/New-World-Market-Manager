module items:block;

import settings;

namespace items {
	Block::Block(const std::string& item_name,
				 const std::string& image_path,
				 const int tier,
				 const bool buy_equals_sell,
				 const double sell_price,
				 const double buy_price,
				 const double base_yield,
				 const double base_craft_tax) :
		RefinedResource(item_name,
						image_path,
						tier,
						buy_equals_sell,
						sell_price,
						buy_price,
						base_yield,
						base_craft_tax) {
	}

	Block::Block(const Json::Value& json_value) :
		RefinedResource(json_value) {
	}

	Json::Value Block::toJson() const {
		Json::Value json_value = RefinedResource::toJson();

		json_value["item_type"] = "Block";

		return json_value;
	}

	double Block::craftTax() const {
		// TODO: implement craft_tax modifiers from settings
		return getBaseCraftTax();
	}

	double Block::yield(const recipe_book::Recipe& recipe) const {
		// Determine the tier of the refining component in the given recipe
		int refining_component_tier = 0;
		for (const auto& [ingredient_name, amount] : recipe.getIngredients()) {
			if (ingredient_name == "Obsidian Sandpaper") {
				refining_component_tier = 5;
				break;
			}
			if (ingredient_name == "Fine Sandpaper") {
				refining_component_tier = 4;
				break;
			}
			if (ingredient_name == "Coarse Sandpaper") {
				refining_component_tier = 3;
				break;
			}
		}

		// Calculate the yield
		const double yield = getBaseYield() + settings::stonecuttingYieldBonus() + refiningComponentYieldBonus(getTier(), refining_component_tier);

		// Return the yield
		return std::max(1., yield) * settings::fortYieldBonusMultiplier();
	}
}
