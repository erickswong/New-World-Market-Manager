#include "ui/content_pages/input_pages/ore_input_page.h"

OreInputPage::OreInputPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void OreInputPage::setItems(Items* items) {
	this->items = items;
}

void OreInputPage::setSettings(Settings* settings) {
	this->settings = settings;
}
