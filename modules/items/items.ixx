export module items;

export import :item;

import "json/json.h";
import :recipes;
import <unordered_map>;

namespace items {
	std::unordered_map<std::string, Item*> items;

	// Set up items
	export void setUp();
	// Resets members to default values
	export void reset() noexcept;

	// Sets members to values from json
	export void fromJson(Json::Value json_value);
	// Returns a json representing this namespace
	export [[nodiscard]] Json::Value toJson();
	// Writes a json representing this namespace to disk
	export void writeToDisk();

	// Returns a pointer to the item with name item_name
	export [[nodiscard]] Item* at(const std::string& item_name);

	// Adds an item to items
	export void insert(const std::string& item_name, Item* item);

	// Analyzes the item
	export void analyze(Item* item);
	// Analyzes the list of items
	export void analyze(const std::list<Item*>& item_update_order);

	// Sets buy_equals_sell for an item
	export void setBuyEqualsSell(Item* item, bool buy_equals_sell);
	// Sets sell_price for an item
	export void setSellPrice(Item* item, double sell_price);
	// Sets but_price for an item
	export void setBuyPrice(Item* item, double buy_price);

	// Sets item update order for all items and returns the master item update order
	export std::list<Item*> itemUpdateOrder();

	export [[nodiscard]] std::unordered_map<std::string, Item*>& get(); // TODO: remove this function?

	std::pair<Recipe, double> getBestInstantCraft(Item* item);
	std::pair<Recipe, double> getBestCraft(Item* item);
	static double profitMargin(double sell_price, double acquire_cost);
};
