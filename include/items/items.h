#pragma once

#include <string>
#include <unordered_map>

#include "item.h"
#include "settings/settings.h"

class Items {
	public:
		~Items();

		void addItem(const std::string& item_name, Item* item);
		
		[[nodiscard]] float getItemBestInstantAcquireCost(const std::string& item_name) const;
		[[nodiscard]] float getItemBestAcquireCost(const std::string& item_name) const;
		[[nodiscard]] float getItemCraftTax(const std::string& item_name, Settings& settings) const;
		[[nodiscard]] float getItemYield(const std::string& item_name, Recipe& recipe, Settings& settings) const;

		[[nodiscard]] int getItemTier(const std::string& item_name) const;

		[[nodiscard]] bool getItemBuyEqualsSell(const std::string& item_name) const;
		void setItemBuyEqualsSell(const std::string& item_name, bool buy_equals_sell, Settings& settings) const;

		[[nodiscard]] float getItemSellPrice(const std::string& item_name) const;
		void setItemSellPrice(const std::string& item_name, float sell_price, Settings& settings) const;

		[[nodiscard]] float getItemBuyPrice(const std::string& item_name) const;
		void setItemBuyPrice(const std::string& item_name, float buy_price, Settings& settings) const;

		[[nodiscard]] float getItemBaseProc(const std::string& item_name) const;

		[[nodiscard]] float getItemBaseCraftTax(const std::string& item_name) const;

		[[nodiscard]] Recipes& getItemRecipes(const std::string& item_name) const;

		[[nodiscard]] std::string getItemImagePath(const std::string& item_name) const;

		[[nodiscard]] ItemAnalysis& getItemAnalysis(const std::string& item_name) const;

		[[nodiscard]] Item* getItem(const std::string& item_name) const;

		[[nodiscard]] std::unordered_map<std::string, Item*> getItems() const;

	private:
		std::unordered_map<std::string, Item*> items;

		void analyzeItem(const std::string& item_name, Settings& settings) const;
		std::tuple<Recipe*, float> itemBestInstantCraftCost(const std::string& item_name, Settings& settings) const;
		std::tuple<Recipe*, float> itemBestCraftCost(const std::string& item_name, Settings& settings) const;
		static float profitMargin(float sell_price, float acquire_cost);

		// TODO: add graph storing nodes with its out edges (maybe in edges as well?) later assert all nodes in items?
};
