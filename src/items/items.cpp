#include "items/items.h"

Items::Items() {
	items = new std::map<std::string, Item>();
}

Items::~Items() {
	delete items;
}

std::map<std::string, Item>* Items::getItems() {
	return items;
}

void Items::addItem(std::string item_name, Item item) {
	items->insert({ item_name, item });
}
