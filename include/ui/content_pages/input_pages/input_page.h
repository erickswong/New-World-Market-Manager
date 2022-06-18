#pragma once

#include <QWidget>
#include "ui_input_page.h"

#include "input_item.h"
import items;

class InputPage final : public QWidget
{
	Q_OBJECT

	public:
		explicit InputPage(QWidget* parent = Q_NULLPTR);

		void addInputItem(std::string item_name);
		void setItems(Items* items);

	private:
		Ui::InputPage ui;
		std::vector<InputItem*> input_items;
		Items* items = nullptr;
};
