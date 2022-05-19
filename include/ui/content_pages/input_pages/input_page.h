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

	void addInputItem(Item* item);

private:
	Ui::InputPage ui;
	std::vector<InputItem*> input_items;
};
