#pragma once

#include <QWidget>
#include "ui_general_settings_input_page.h"

class GeneralSettingsInputPage final : public QWidget
{
	Q_OBJECT

public:
	explicit GeneralSettingsInputPage(QWidget *parent = Q_NULLPTR);

private:
	Ui::GeneralSettingsInputPage ui;
};
