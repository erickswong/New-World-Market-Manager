#include "ui/content_pages/input_pages/input_items/input_resource.h"

import items;

using items::Resource;

InputResource::InputResource(const std::string& resource_name, QWidget *parent)
	: InputItem(parent),
      resource_name(resource_name) {
	// Insert this into the cyclic list
	if (const auto& [element, isFirst] = input_resource_map.insert({ resource_name, this }); isFirst) {
		prev = this;
		next = this;
	} else {
		const auto first = (*element).second;
		const auto last = first->prev;
		prev = last;
		next = first;
		last->next = this;
		first->prev = this;
	}

	// Set up ui
	ui.setupUi(this);

	// Get resource
	Resource* resource = dynamic_cast<Resource*>(items::at(resource_name));

	// Set image
	ui.image->setPixmap(QPixmap(QString(resource->getImagePath().c_str())));

	// Set label
	ui.label->setText(QCoreApplication::translate("InputResource", resource->getItemName().c_str(), nullptr));

	// Set lock
	ui.lock->setChecked(resource->getBuyEqualsSell());

	// Set sell price
	ui.sell_price->setValue(resource->getSellPrice());

	// Set buy price
	ui.buy_price->setReadOnly(resource->getBuyEqualsSell());
	ui.buy_price->setValue(resource->getBuyPrice());
}

InputResource::~InputResource() {
	// This is the only InputResource in its cyclic list
	if (next == this) {
		input_resource_map.erase(resource_name);
		return;
	}

	// This is a pointed to InputResource in input_resource_map
	if (auto& first = input_resource_map.at(resource_name); first == this) {
		first = next;
	}

	// Remove from cyclic list
	prev->next = next;
	next->prev = prev;
}

void InputResource::on_lock_toggled(const bool buy_equals_sell) const {
	// Get resource
	Resource* resource = dynamic_cast<Resource*>(items::at(resource_name));

	// Set buy equal sell for resource, updating buy price if needed, and analyze if necessary
	items::setBuyEqualsSell(resource, buy_equals_sell);

	// Set display to reflect buy equals sell state
	ui.buy_price->setReadOnly(buy_equals_sell);

	// Set buy price display to reflect up-to-date buy price
	// Will not call analyze again as no change is guaranteed
	ui.buy_price->setValue(resource->getBuyPrice());

	// Update next InputResource in the cyclic list
	next->ui.lock->setChecked(buy_equals_sell);
}

void InputResource::on_sell_price_valueChanged(const double sell_price) const {
	// Get resource
	Resource* resource = dynamic_cast<Resource*>(items::at(resource_name));

	// Set sell price for resource, updating buy price if needed, and analyze if necessary
	items::setSellPrice(resource, sell_price);

	// Set buy price display to reflect up-to-date buy price
	// Will not call analyze again as no change is guaranteed
	ui.buy_price->setValue(resource->getBuyPrice());

	// Update next InputResource in the cyclic list
	next->ui.sell_price->setValue(sell_price);
}

void InputResource::on_buy_price_valueChanged(const double buy_price) const {
	// Get resource
	Resource* resource = dynamic_cast<Resource*>(items::at(resource_name));

	// Set buy price for resource and analyze if necessary
	items::setBuyPrice(resource, buy_price);

	// Update next InputResource in the cyclic list
	next->ui.buy_price->setValue(buy_price);
}
