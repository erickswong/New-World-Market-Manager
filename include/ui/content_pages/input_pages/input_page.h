#pragma once

#include <QWidget>
#include "ui_input_page.h"

#include "input_item.h"

class InputPage final : public QWidget
{
	Q_OBJECT

	public:
		explicit InputPage(QWidget* parent = Q_NULLPTR);
		~InputPage();

		void addInputItem(std::string item_name);

	private:
		Ui::InputPage ui;
		std::vector<InputItem*> input_items;
};
