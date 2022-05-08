#pragma once

#include <map>
#include <string>
#include "item.h"

class Items {
	public:
		Items();
		~Items();

		[[nodiscard]] Item& getItem(const std::string& item_name) const;
		void addItem(const std::string& item_name, const Item& item) const;

		[[nodiscard]] std::map<std::string, Item>* getItems() const;

	private:
		std::map<std::string, Item>* items;
};
