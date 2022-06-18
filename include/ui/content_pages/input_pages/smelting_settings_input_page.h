#pragma once

#include <QWidget>
#include "ui_smelting_settings_input_page.h"

import items;

class SmeltingSettingsInputPage final : public QWidget
{
	Q_OBJECT

	public:
		explicit SmeltingSettingsInputPage(QWidget *parent = Q_NULLPTR);

		void setItems(Items* items);

	private:
		Ui::SmeltingSettingsInputPage ui;
		Items* items = nullptr;
};
