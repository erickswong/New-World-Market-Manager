#include "ui/content_pages/input_pages/smelting_settings_input_page.h"

SmeltingSettingsInputPage::SmeltingSettingsInputPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

void SmeltingSettingsInputPage::setItems(Items* items) {
	this->items = items;

	// Set items for all children
	ui.general_settings_input_page->setItems(items);
}

void SmeltingSettingsInputPage::setSettings(Settings* settings) {
	this->settings = settings;

	// Set settings for all children
	ui.general_settings_input_page->setSettings(settings);
}
