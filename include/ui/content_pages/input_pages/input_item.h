#pragma once

#include <QWidget>
#include "ui_input_item.h"

import items;
import settings;

class InputItem final : public QWidget
{
	Q_OBJECT

	public:
		explicit InputItem(Item* item, Items* items, Settings* settings, QWidget* parent = Q_NULLPTR);
		void setItems(Items* items);
		void setSettings(Settings* settings);

private slots:
		void on_lock_clicked(bool buy_equals_sell) const;
		void on_sell_price_valueChanged(double sell_price) const;
		void on_buy_price_valueChanged(double buy_price) const;

	private:
		Ui::InputItem ui;
		Item* item;
		Items* items = nullptr;
		Settings* settings = nullptr;

		// TODO: add function to call display update
};
