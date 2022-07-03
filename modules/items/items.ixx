export module items;

export import :gear;
export import :item;
export import :block;
export import :cloth;
export import :ingot;
export import :leather;
export import :plank;
export import :raw_resource;
export import :refined_resource;
export import :refining_component;
export import :resource;

import "json/json.h";
import :refined_resource;
import <unordered_map>;

namespace items {
	std::unordered_map<std::string, Item*> items;

	// Set up items
	export void setUp();
	// Resets members to default values
	export void reset() noexcept;

	// Sets members to values from json
	export void fromJson(const Json::Value& json_value);
	// Returns a json representing items
	export [[nodiscard]] Json::Value toJson();
	// Writes a json representing this namespace to disk
	export void writeToDisk(); // TODO: enum for write modes (normal, extra, debug etc)

	// Returns a pointer to the item with name item_name
	export template<typename T>
	[[nodiscard]] T* getItem(const std::string& item_name);

	// Adds an item to items
	export void addItem(Item* item);

	// Updates the refined resource
	export void update(RefinedResource* refined_resource);
	// Updates the list of items
	export void update(const std::list<Item*>& item_update_order);

	// Sets buy_equals_sell for an item
	export void setBuyEqualsSell(Item* item, bool buy_equals_sell);
	// Sets sell_price for an item
	export void setSellPrice(Item* item, double sell_price);
	// Sets buy_price for an item
	export void setBuyPrice(Item* item, double buy_price);

	// Sets item update order for all items and returns the master item update order
	export std::list<Item*> itemUpdateOrder();

	// Finds and saves the best instant craft cost and recipe for refined_resource
	void bestInstantCraft(RefinedResource* refined_resource);
	// Finds and saves the best craft cost and recipe for refined_resource
	void bestCraft(RefinedResource* refined_resource);
};

template<typename T>
T* items::getItem(const std::string& item_name) {
	return dynamic_cast<T*>(items.at(item_name));
}
