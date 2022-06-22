#pragma once

#include "input_item.h"
#include "ui_input_resource.h"

class InputResource final : public InputItem {
	Q_OBJECT

	Ui::InputResource ui;
	std::string resource_name;

	public:
		explicit InputResource(const std::string& resource_name, QWidget* parent = Q_NULLPTR);

	private slots:
		void on_lock_clicked(bool buy_equals_sell) const;
		void on_sell_price_valueChanged(double sell_price) const;
		void on_buy_price_valueChanged(double buy_price) const;
};
