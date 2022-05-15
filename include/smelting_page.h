#pragma once

#include <QWidget>
#include "ui_smelting_page.h"

class SmeltingPage : public QWidget
{
	Q_OBJECT

public:
	SmeltingPage(QWidget *parent = Q_NULLPTR);
	~SmeltingPage();

private:
	Ui::SmeltingPage ui;
};
