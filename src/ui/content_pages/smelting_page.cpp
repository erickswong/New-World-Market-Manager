#include "ui/content_pages/smelting_page.h"

SmeltingPage::SmeltingPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

    // Set stacked widget to default page
    ui.input_pages->setCurrentIndex(static_cast<int>(InputPageButtons::FLUX));
}

void SmeltingPage::setItems(Items* items) {
	this->items = items;

    // Set items for all children
    ui.flux_input_page->setItems(items);
    ui.ore_input_page->setItems(items);
    ui.ingot_input_page->setItems(items);
    ui.settings_input_page->setItems(items);
}

void SmeltingPage::setSettings(Settings* settings) {
	this->settings = settings;

    // Set settings for all children
    ui.flux_input_page->setSettings(settings);
    ui.ore_input_page->setSettings(settings);
    ui.ingot_input_page->setSettings(settings);
    ui.settings_input_page->setSettings(settings);
}

void SmeltingPage::on_flux_input_button_clicked() {
	ui.flux_input_button->setChecked(true);
	inputPageButtonClicked(InputPageButtons::FLUX);
}

void SmeltingPage::on_ore_input_button_clicked() {
	ui.ore_input_button->setChecked(true);
	inputPageButtonClicked(InputPageButtons::ORE);
}

void SmeltingPage::on_ingot_input_button_clicked() {
	ui.ingot_input_button->setChecked(true);
	inputPageButtonClicked(InputPageButtons::INGOT);
}

void SmeltingPage::on_settings_input_button_clicked() {
	ui.settings_input_button->setChecked(true);
	inputPageButtonClicked(InputPageButtons::SETTINGS);
}

void SmeltingPage::inputPageButtonClicked(const InputPageButtons button) const {
    // Uncheck every other button
    if (button != InputPageButtons::FLUX) {
        ui.flux_input_button->setChecked(false);
    }
    if (button != InputPageButtons::ORE) {
        ui.ore_input_button->setChecked(false);
    }
    if (button != InputPageButtons::INGOT) {
        ui.ingot_input_button->setChecked(false);
    }
    if (button != InputPageButtons::SETTINGS) {
        ui.settings_input_button->setChecked(false);
    }

    // Set stacked widget to correct page
    ui.input_pages->setCurrentIndex(static_cast<int>(button));
}
