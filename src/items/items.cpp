#include "items/items.h"

Items::Items() : items(new std::map<std::string, Item>()) {
}

Items::~Items() {
	delete items;
}

Item& Items::getItem(const std::string& item_name) const {
	return items->at(item_name);
}

void Items::addItem(const std::string& item_name, const Item& item) const {
	items->insert({ item_name, item });
}

std::map<std::string, Item>* Items::getItems() const {
	return items;
}
