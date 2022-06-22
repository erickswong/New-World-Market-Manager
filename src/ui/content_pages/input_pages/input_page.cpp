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

void InputPage::addInputResource(const std::string resource_name) {
	const auto input_item = new InputResource(resource_name, this);

	input_items.push_back(input_item);

	ui.verticalLayout->insertWidget(ui.verticalLayout->count() - 1, input_item);
}
