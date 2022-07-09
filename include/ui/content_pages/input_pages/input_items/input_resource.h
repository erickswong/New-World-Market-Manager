#pragma once

#include <list>
#include <unordered_map>

#include "input_item.h"
#include "ui_input_resource.h"

import items;

using items::Resource;

class InputResource final : public InputItem {
	Q_OBJECT

	Ui::InputResource ui;
	Resource* resource;

	public:
		InputResource(const std::string& resource_name, QWidget* parent = Q_NULLPTR);

	private slots:
		void on_lock_toggled(bool buy_equals_sell) const;
		void on_sell_price_valueChanged(double sell_price) const;
		void on_buy_price_valueChanged(double buy_price) const;
};
