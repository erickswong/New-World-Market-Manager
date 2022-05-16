#pragma once

#include <QWidget>
#include "ui_ore_input_page.h"

#include "items/items.h"

class OreInputPage final : public QWidget
{
	Q_OBJECT

	public:
		explicit OreInputPage(QWidget *parent = Q_NULLPTR);

		void setItems(Items* items);
		void setSettings(Settings* settings);

	private:
		Ui::OreInputPage ui;
		Items* items = nullptr;
		Settings* settings = nullptr;
};
