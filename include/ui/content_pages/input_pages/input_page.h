#pragma once

#include <QWidget>
#include "ui_input_page.h"

#include "input_items/input_item.h"

class InputPage final : public QWidget {
	Q_OBJECT

	Ui::InputPage ui;
	std::forward_list<InputItem*> input_items;

	public:
		explicit InputPage(QWidget* parent = Q_NULLPTR);
		~InputPage();

		// Adds an InputItem to this InputPage
		void addInputItem(InputItem* input_item);
};
