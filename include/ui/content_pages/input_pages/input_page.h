#pragma once

#include <QWidget>
#include "ui_input_page.h"

#include "input_item.h"
import items;
import settings;

class InputPage final : public QWidget
{
	Q_OBJECT

	public:
		explicit InputPage(QWidget* parent = Q_NULLPTR);

		void addInputItem(std::string item_name);
		void setItems(Items* items);
		void setSettings(Settings* settings);

	private:
		Ui::InputPage ui;
		std::vector<InputItem*> input_items;
		Items* items = nullptr;
		Settings* settings = nullptr;
};
