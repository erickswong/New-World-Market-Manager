#pragma once

#include <QWidget>
#include "ui_general_settings_input_page.h"

import items;
import settings;

class GeneralSettingsInputPage final : public QWidget
{
	Q_OBJECT

public:
	explicit GeneralSettingsInputPage(QWidget *parent = Q_NULLPTR);

	void setItems(Items* items);
	void setSettings(Settings* settings);

private:
	Ui::GeneralSettingsInputPage ui;
	Items* items = nullptr;
	Settings* settings = nullptr;
};
