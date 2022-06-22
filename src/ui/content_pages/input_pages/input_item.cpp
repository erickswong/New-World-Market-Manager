#include "ui/content_pages/input_pages/input_item.h"

import items;

using items::Resource;

InputItem::InputItem(const std::string& item_name, QWidget *parent)
	: QWidget(parent),
      item_name(item_name) {
	// Set up ui
	ui.setupUi(this);

	// Get resource
	Resource* resource = dynamic_cast<Resource*>(items::at(item_name));

	// Set image
	ui.image->setPixmap(QPixmap(QString(resource->getImagePath().c_str())));

	// Set label
	ui.label->setText(QCoreApplication::translate("InputItem", resource->getItemName().c_str(), nullptr));

	// Set lock
	ui.lock->setChecked(resource->getBuyEqualsSell());

	// Set sell price
	ui.sell_price->setValue(resource->getSellPrice());

	// Set buy price
	ui.buy_price->setReadOnly(resource->getBuyEqualsSell());
	ui.buy_price->setValue(resource->getBuyPrice());
}

void InputItem::on_lock_clicked(const bool buy_equals_sell) const {
	// Get resource
	Resource* resource = dynamic_cast<Resource*>(items::at(item_name));

	// Set buy equal sell for item, updating buy price if needed, and analyze if necessary
	items::setBuyEqualsSell(resource, buy_equals_sell);

	// Set display to reflect buy equals sell state
	ui.buy_price->setReadOnly(buy_equals_sell);

	// Set buy price display to reflect up-to-date buy price
	// Will not call analyze again as no change is guaranteed
	ui.buy_price->setValue(resource->getBuyPrice());
}

void InputItem::on_sell_price_valueChanged(const double sell_price) const {
	// Get resource
	Resource* resource = dynamic_cast<Resource*>(items::at(item_name));

	// Set sell price for item, updating buy price if needed, and analyze if necessary
	items::setSellPrice(resource, sell_price);

	// Set buy price display to reflect up-to-date buy price
	// Will not call analyze again as no change is guaranteed
	ui.buy_price->setValue(resource->getBuyPrice());
}

void InputItem::on_buy_price_valueChanged(const double buy_price) const {
	// Get resource
	Resource* resource = dynamic_cast<Resource*>(items::at(item_name));

	// Set buy price for item and analyze if necessary
	items::setBuyPrice(resource, buy_price);
}
