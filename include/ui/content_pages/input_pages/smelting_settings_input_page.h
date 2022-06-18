#pragma once

#include <QWidget>
#include "ui_smelting_settings_input_page.h"

class SmeltingSettingsInputPage final : public QWidget
{
	Q_OBJECT

	public:
		explicit SmeltingSettingsInputPage(QWidget *parent = Q_NULLPTR);

	private:
		Ui::SmeltingSettingsInputPage ui;
};
