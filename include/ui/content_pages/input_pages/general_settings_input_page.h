#pragma once

#include <QWidget>
#include "ui_general_settings_input_page.h"

class GeneralSettingsInputPage final : public QWidget { // TODO: deprecate
	Q_OBJECT

	Ui::GeneralSettingsInputPage ui;

	public:
		explicit GeneralSettingsInputPage(QWidget *parent = Q_NULLPTR);
};
