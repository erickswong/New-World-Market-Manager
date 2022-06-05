#pragma once

#include <QWidget>

#include "input_item.h"
#include "ui_input_page.h"

#include "items/item.h"

class InputPage final : public QWidget
{
	Q_OBJECT

	public:
		explicit InputPage(QWidget* parent = Q_NULLPTR);

		// TODO: change from Item* to string param
		void addInputItem(std::string item_name);
		void setItems(Items* items);
		void setSettings(Settings* settings);

	private:
		Ui::InputPage ui;
		std::vector<InputItem*> input_items;
		Items* items = nullptr;
		Settings* settings = nullptr;
};
