#pragma once

#include <string>
#include <unordered_map>

#include "item.h"
#include "settings/settings.h"

class Items {
	public:
		Items();
		~Items();

		void addItem(const std::string& item_name, Item* item) const;

		[[nodiscard]] double getItemBestInstantAcquireCost(const std::string& item_name) const;
		[[nodiscard]] double getItemBestAcquireCost(const std::string& item_name) const;
		[[nodiscard]] double getItemCraftTax(const std::string& item_name, Settings& settings) const;
		[[nodiscard]] double getItemYield(const std::string& item_name, Recipe& recipe, Settings& settings) const;

		[[nodiscard]] int getItemTier(const std::string& item_name) const;

		[[nodiscard]] bool getItemBuyEqualsSell(const std::string& item_name) const;
		void setItemBuyEqualsSell(const std::string& item_name, bool buy_equals_sell, Settings& settings) const;

		[[nodiscard]] double getItemSellPrice(const std::string& item_name) const;
		void setItemSellPrice(const std::string& item_name, double sell_price, Settings& settings) const;

		[[nodiscard]] double getItemBuyPrice(const std::string& item_name) const;
		void setItemBuyPrice(const std::string& item_name, double buy_price, Settings& settings) const;

		[[nodiscard]] double getItemBaseProc(const std::string& item_name) const;

		[[nodiscard]] double getItemBaseCraftTax(const std::string& item_name) const;

		[[nodiscard]] Recipes* getItemRecipes(const std::string& item_name) const;

		[[nodiscard]] std::string getItemImagePath(const std::string& item_name) const;

		[[nodiscard]] ItemAnalysis& getItemAnalysis(const std::string& item_name) const;

		[[nodiscard]] std::unordered_map<std::string, Item*>* getItems() const;

	private:
		std::unordered_map<std::string, Item*>* items;

		[[nodiscard]] Item* getItem(const std::string& item_name) const;

		void analyzeItem(const std::string& item_name, Settings& settings) const;
		double itemBestInstantCraftCost(const std::string& item_name, Settings& settings) const;
		double itemBestCraftCost(const std::string& item_name, Settings& settings) const;
		static double profitMargin(double sell_price, double acquire_cost);

		// TODO: add graph storing nodes with its out edges (maybe in edges as well?) later assert all nodes in items?
};
