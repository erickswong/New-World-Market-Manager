export module items;

export import :item;

import "json/json.h";
import recipes;
import <unordered_map>;

// Forward declaration
class Items;

namespace items {
	// Initializes Items and returns a pointer to it
	export Items* init();
};


export class Items {
	public:
		Items();
		explicit Items(Json::Value json_value);
		~Items();

		void writeToDisk() const;
		[[nodiscard]] Json::Value toJson() const;

		[[nodiscard]] std::unordered_map<std::string, Item*>& get();

		[[nodiscard]] Item* at(const std::string& item_name) const;

		void insert(const std::string& item_name, Item* item);

		void analyze(Item* item) const;
		void analyze(const std::list<Item*>& item_update_order) const;

		void setBuyEqualsSell(Item* item, bool buy_equals_sell) const;

		void setSellPrice(Item* item, double sell_price) const;

		void setBuyPrice(Item* item, double buy_price) const;

	private:
		std::unordered_map<std::string, Item*> items;

		std::pair<Recipe, double> getBestInstantCraft(Item* item) const;
		std::pair<Recipe, double> getBestCraft(Item* item) const;
		static double profitMargin(double sell_price, double acquire_cost);

		std::list<Item*> itemUpdateOrder();
};
