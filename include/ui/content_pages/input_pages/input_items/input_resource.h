#pragma once

#include <list>
#include <unordered_map>

#include "input_item.h"
#include "ui_input_resource.h"

// A cyclic list is used here so that when a Resource is represented by multiple InputResources, changing one will change all.

// Forward Declaration
class InputResource;

static std::unordered_map<std::string, InputResource*> input_resource_map; // Stores a map from resource_name to an InputResource to be considered the first in the cyclic list

class InputResource final : public InputItem {
	Q_OBJECT

	Ui::InputResource ui;
	std::string resource_name; // TODO: save Resource* instead and add function for pointer update
	InputResource* prev;       // The previous InputResource in the cyclic list
	InputResource* next;       // The next InputResource in the cyclic list

	public:
		explicit InputResource(const std::string& resource_name, QWidget* parent = Q_NULLPTR);
		~InputResource();

	private slots:
		void on_lock_toggled(bool buy_equals_sell) const;
		void on_sell_price_valueChanged(double sell_price) const;
		void on_buy_price_valueChanged(double buy_price) const;
};
