#pragma once

#include <QWidget>
#include "ui_input_item.h"

class InputItem final : public QWidget { // TODO: Rename to InputResource, later add Input____ for other types
	Q_OBJECT

	Ui::InputItem ui;
	std::string item_name;

	public:
		explicit InputItem(const std::string& item_name, QWidget* parent = Q_NULLPTR);

	private slots:
		void on_lock_clicked(bool buy_equals_sell) const;
		void on_sell_price_valueChanged(double sell_price) const;
		void on_buy_price_valueChanged(double buy_price) const;
};
