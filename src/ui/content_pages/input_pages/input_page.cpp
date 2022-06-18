#include "ui/content_pages/input_pages/input_page.h"

InputPage::InputPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void InputPage::addInputItem(const std::string item_name) {
	const auto input_item = new InputItem(items->at(item_name), items, this);

	input_items.push_back(input_item);

	ui.verticalLayout->insertWidget(ui.verticalLayout->count() - 1, input_item);
}

void InputPage::setItems(Items* items) {
	this->items = items;

	// Set items for all children
	for (const auto& input_item : input_items) {
		input_item->setItems(items);
	}
}
