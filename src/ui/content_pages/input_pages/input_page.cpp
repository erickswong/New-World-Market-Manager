#include "ui/content_pages/input_pages/input_page.h"

InputPage::InputPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

InputPage::~InputPage() {
	for (const auto& input_item : input_items) {
		delete input_item;
	}
}

void InputPage::addInputItem(const std::string item_name) {
	const auto input_item = new InputItem(item_name, this);

	input_items.push_back(input_item);

	ui.verticalLayout->insertWidget(ui.verticalLayout->count() - 1, input_item);
}
