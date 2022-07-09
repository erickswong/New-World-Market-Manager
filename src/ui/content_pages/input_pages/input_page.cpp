#include "ui/content_pages/input_pages/input_page.h"
#include "ui/content_pages/input_pages/input_items/input_resource.h"

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

void InputPage::addInputItem(InputItem* input_item) {
	// Push input_item into input_items
	input_items.push_front(input_item);

	// Set this as parent of input_item
	input_item->setParent(this);

	// Insert input_item into ui
	ui.verticalLayout->insertWidget(ui.verticalLayout->count() - 1, input_item);
}
