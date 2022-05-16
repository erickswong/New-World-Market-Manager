#include "ui/content_pages/input_pages/flux_input_page.h"

FluxInputPage::FluxInputPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void FluxInputPage::setItems(Items* items) {
	this->items = items;
}

void FluxInputPage::setSettings(Settings* settings) {
	this->settings = settings;
}
