#pragma once

#include <string>
#include <unordered_map>

#include "item.h"
#include "settings/settings.h"

class Items {
	public:
		Items(Settings* settings);
		explicit Items(Json::Value json_value, Settings* settings);
		~Items();

		void writeToDisk() const;
		[[nodiscard]] Json::Value toJson() const;

		[[nodiscard]] std::unordered_map<std::string, Item*>& get();

		[[nodiscard]] Item* at(const std::string& item_name) const;

		void insert(const std::string& item_name, Item* item);
		
		void analyze(Item* item, Settings* settings) const;
		void analyze(const std::list<Item*>& item_update_order, Settings* settings) const;
		
		void setBuyEqualsSell(Item* item, bool buy_equals_sell, Settings* settings) const;
		
		void setSellPrice(Item* item, double sell_price, Settings* settings) const;
		
		void setBuyPrice(Item* item, double buy_price, Settings* settings) const;

	private:
		std::unordered_map<std::string, Item*> items;

		std::pair<Recipe, double> getBestInstantCraft(Item* item, Settings* settings) const;
		std::pair<Recipe, double> getBestCraft(Item* item, Settings* settings) const;
		static double profitMargin(double sell_price, double acquire_cost);

		std::list<Item*> setItemUpdateOrders();
};
