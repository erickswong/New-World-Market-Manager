#include "ui/content_pages/smelting_page.h"

SmeltingPage::SmeltingPage(QWidget *parent)
	: QWidget(parent) {
	ui.setupUi(this);

    // Set stacked widget to default page
    ui.input_pages->setCurrentIndex(static_cast<int>(InputPageButtons::FLUX));

    // Setup input pages
    setUpInputPages();
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
    ui.flux_input_page->addInputResource("Obsidian Flux");
}

void SmeltingPage::setUpOreInputPage() const {
    ui.ore_input_page->addInputResource("Iron Ore");
    ui.ore_input_page->addInputResource("Starmetal Ore");
    ui.ore_input_page->addInputResource("Orichalcum Ore");
    ui.ore_input_page->addInputResource("Silver Ore");
    ui.ore_input_page->addInputResource("Gold Ore");
    ui.ore_input_page->addInputResource("Platinum Ore");
    ui.ore_input_page->addInputResource("Cinnabar");
    ui.ore_input_page->addInputResource("Tolvium");
}

void SmeltingPage::setUpIngotInputPage() const {
    ui.ingot_input_page->addInputResource("Charcoal");
    ui.ingot_input_page->addInputResource("Iron Ingot");
    ui.ingot_input_page->addInputResource("Steel Ingot");
    ui.ingot_input_page->addInputResource("Starmetal Ingot");
    ui.ingot_input_page->addInputResource("Orichalcum Ingot");
    ui.ingot_input_page->addInputResource("Silver Ingot");
    ui.ingot_input_page->addInputResource("Gold Ingot");
    ui.ingot_input_page->addInputResource("Platinum Ingot");
    ui.ingot_input_page->addInputResource("Asmodeum");
}
