#pragma once

#include <QWidget>
#include "ui_smelting_settings_input_page.h"

class SmeltingSettingsInputPage final : public QWidget { // TODO: deprecate
	Q_OBJECT

	Ui::SmeltingSettingsInputPage ui;

	public:
		explicit SmeltingSettingsInputPage(QWidget *parent = Q_NULLPTR);
};
