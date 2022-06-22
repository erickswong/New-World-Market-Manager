#include "ui/content_pages/input_pages/input_items/input_resource.h"

import items;

using items::Resource;

InputResource::InputResource(const std::string& resource_name, QWidget *parent)
	: InputItem(parent),
      resource_name(resource_name) {
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

void InputResource::on_lock_clicked(const bool buy_equals_sell) const {
	// Get resource
	Resource* resource = dynamic_cast<Resource*>(items::at(resource_name));

	// Set buy equal sell for resource, updating buy price if needed, and analyze if necessary
	items::setBuyEqualsSell(resource, buy_equals_sell);

	// Set display to reflect buy equals sell state
	ui.buy_price->setReadOnly(buy_equals_sell);

	// Set buy price display to reflect up-to-date buy price
	// Will not call analyze again as no change is guaranteed
	ui.buy_price->setValue(resource->getBuyPrice());
}

void InputResource::on_sell_price_valueChanged(const double sell_price) const {
	// Get resource
	Resource* resource = dynamic_cast<Resource*>(items::at(resource_name));

	// Set sell price for resource, updating buy price if needed, and analyze if necessary
	items::setSellPrice(resource, sell_price);

	// Set buy price display to reflect up-to-date buy price
	// Will not call analyze again as no change is guaranteed
	ui.buy_price->setValue(resource->getBuyPrice());
}

void InputResource::on_buy_price_valueChanged(const double buy_price) const {
	// Get resource
	Resource* resource = dynamic_cast<Resource*>(items::at(resource_name));

	// Set buy price for resource and analyze if necessary
	items::setBuyPrice(resource, buy_price);
}
