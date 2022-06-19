#pragma once

#include <QWidget>
#include "ui_smelting_page.h"

class SmeltingPage final : public QWidget {
	Q_OBJECT

	Ui::SmeltingPage ui;

	enum class InputPageButtons {
		FLUX,
		ORE,
		INGOT,
		SETTINGS
	};

	public:
		explicit SmeltingPage(QWidget* parent = Q_NULLPTR);

	private slots:
		void on_flux_input_button_clicked() const;
		void on_ore_input_button_clicked() const;
		void on_ingot_input_button_clicked() const;
		void on_settings_input_button_clicked() const;

	private:
		void inputPageButtonClicked(InputPageButtons button) const;

		void setUpInputPages() const;
		void setUpFluxInputPage() const;
		void setUpOreInputPage() const;
		void setUpIngotInputPage() const;
};
