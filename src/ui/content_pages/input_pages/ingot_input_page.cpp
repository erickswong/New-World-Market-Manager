#include "ui/content_pages/input_pages/ingot_input_page.h"

IngotInputPage::IngotInputPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void IngotInputPage::setItems(Items* items) {
	this->items = items;
}

void IngotInputPage::setSettings(Settings* settings) {
	this->settings = settings;
}
