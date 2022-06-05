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

    // Setup input pages
    setUpInputPages();
}

void SmeltingPage::setSettings(Settings* settings) {
	this->settings = settings;

    // Set settings for all children
    ui.flux_input_page->setSettings(settings);
    ui.ore_input_page->setSettings(settings);
    ui.ingot_input_page->setSettings(settings);
    ui.settings_input_page->setSettings(settings);
}

void SmeltingPage::on_flux_input_button_clicked() const {
	ui.flux_input_button->setChecked(true);
	inputPageButtonClicked(InputPageButtons::FLUX);
}

void SmeltingPage::on_ore_input_button_clicked() const {
	ui.ore_input_button->setChecked(true);
	inputPageButtonClicked(InputPageButtons::ORE);
}

void SmeltingPage::on_ingot_input_button_clicked() const {
	ui.ingot_input_button->setChecked(true);
	inputPageButtonClicked(InputPageButtons::INGOT);
}

void SmeltingPage::on_settings_input_button_clicked() const {
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

void SmeltingPage::setUpInputPages() const {
    setUpFluxInputPage();
    setUpOreInputPage();
    setUpIngotInputPage();
}

void SmeltingPage::setUpFluxInputPage() const {
    ui.flux_input_page->addInputItem("Sand Flux");
    ui.flux_input_page->addInputItem("Shelldust Flux");
    ui.flux_input_page->addInputItem("Obsidian Flux");
}

void SmeltingPage::setUpOreInputPage() const {
    ui.ore_input_page->addInputItem("Iron Ore");
    ui.ore_input_page->addInputItem("Starmetal Ore");
    ui.ore_input_page->addInputItem("Orichalcum Ore");
    ui.ore_input_page->addInputItem("Silver Ore");
    ui.ore_input_page->addInputItem("Gold Ore");
    ui.ore_input_page->addInputItem("Platinum Ore");
    ui.ore_input_page->addInputItem("Cinnabar");
    ui.ore_input_page->addInputItem("Tolvium");
}

void SmeltingPage::setUpIngotInputPage() const {
    ui.ingot_input_page->addInputItem("Charcoal");
    ui.ingot_input_page->addInputItem("Iron Ingot");
    ui.ingot_input_page->addInputItem("Steel Ingot");
    ui.ingot_input_page->addInputItem("Starmetal Ingot");
    ui.ingot_input_page->addInputItem("Orichalcum Ingot");
    ui.ingot_input_page->addInputItem("Silver Ingot");
    ui.ingot_input_page->addInputItem("Gold Ingot");
    ui.ingot_input_page->addInputItem("Platinum Ingot");
    ui.ingot_input_page->addInputItem("Asmodeum");
}
