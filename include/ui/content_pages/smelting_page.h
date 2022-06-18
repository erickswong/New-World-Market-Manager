#pragma once

#include <QWidget>
#include "ui_smelting_page.h"

import items;

class SmeltingPage final : public QWidget {
	Q_OBJECT

	public:
		explicit SmeltingPage(QWidget* parent = Q_NULLPTR);

		void setItems(Items* items);

	private slots:
		void on_flux_input_button_clicked() const;
		void on_ore_input_button_clicked() const;
		void on_ingot_input_button_clicked() const;
		void on_settings_input_button_clicked() const;

	private:
		Ui::SmeltingPage ui;
		Items* items = nullptr;

		enum class InputPageButtons {
			FLUX,
			ORE,
			INGOT,
			SETTINGS
		};

		void inputPageButtonClicked(InputPageButtons button) const;

		void setUpInputPages() const;
		void setUpFluxInputPage() const;
		void setUpOreInputPage() const;
		void setUpIngotInputPage() const;
};
