#include "ui/content_pages/input_pages/input_items/input_item.h"

InputItem::InputItem(const std::string& name, QWidget *parent) :
	QWidget(parent),
    name(name) {
	insertIntoCyclicList();
}

InputItem::~InputItem() {
	removeFromCyclicList();
}

std::string InputItem::getName() const {
	return name;
}

void InputItem::insertIntoCyclicList() {
	// Try to insert this into input_item_map
	if (const auto& [element, isFirst] = input_item_map.insert({ name, this }); isFirst) {
		// This was inserted into input_item_map (i.e. this is the only InputItem in its cyclic list)

		// Insert this into its cyclic list
		prev = this;
		next = this;
	} else {
		// This was not inserted into input_item map (i.e. there was already another InputItem in its cyclic list)

		// Get the first and last InputItem in its cyclic list
		const auto first = (*element).second;
		const auto last = first->prev;

		// Insert this into its cyclic list
		prev = last;
		next = first;
		last->next = this;
		first->prev = this;
	}
}

void InputItem::removeFromCyclicList() {
	// This is the only InputItem in its cyclic list
	if (next == this) {
		input_item_map.erase(name);
		return;
	}

	// This is a pointed to InputItem in input_item_map (i.e. this is considered the first InputItem of its cyclic list)
	if (auto& first = input_item_map.at(name); first == this) {
		// Change the first InputItem to another InputItem (next) before removing
		first = next;
	}

	// Remove from its cyclic list
	prev->next = next;
	next->prev = prev;
}
