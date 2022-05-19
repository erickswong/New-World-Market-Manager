#include "ui/content_pages/input_pages/input_page.h"

InputPage::InputPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void InputPage::addInputItem(Item* item) {
	const auto input_item = new InputItem(item, this);

	input_items.push_back(input_item);

	ui.verticalLayout->insertWidget(ui.verticalLayout->count() - 1, input_item);
}
