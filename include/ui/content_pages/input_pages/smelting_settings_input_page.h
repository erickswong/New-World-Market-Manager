#pragma once

#include <QWidget>
#include "ui_smelting_settings_input_page.h"

#include "items/items.h"

class SmeltingSettingsInputPage final : public QWidget
{
	Q_OBJECT

	public:
		explicit SmeltingSettingsInputPage(QWidget *parent = Q_NULLPTR);

		void setItems(Items* items);
		void setSettings(Settings* settings);

	private:
		Ui::SmeltingSettingsInputPage ui;
		Items* items = nullptr;
		Settings* settings = nullptr;
};
