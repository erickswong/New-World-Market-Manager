#pragma once

#include <map>
#include <string>
#include "item.h"

class Items {
	public:
		Items();
		~Items();

		std::map<std::string, Item>* getItems();
		void addItem(std::string item_name, Item item);

	private:
		std::map<std::string, Item>* items;
};
