#include "ui/content_pages/input_pages/input_items/input_resource.h"

InputResource::InputResource(const std::string& resource_name, QWidget *parent) :
	InputItem(resource_name, parent),
    resource(items::getItem<Resource>(resource_name)) {
	// Set up ui
	ui.setupUi(this);

	// Set image
	ui.image->setPixmap(QPixmap(QString(resource->imagePath().c_str())));

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

void InputResource::on_lock_toggled(const bool buy_equals_sell) const {
	// Set buy equal sell for resource, updating buy price if needed, and analyze if necessary
	items::setBuyEqualsSell(resource, buy_equals_sell);

	// Set display to reflect buy equals sell state
	ui.buy_price->setReadOnly(buy_equals_sell);

	// Set buy price display to reflect up-to-date buy price
	// Will not call analyze again as no change is guaranteed
	ui.buy_price->setValue(resource->getBuyPrice());

	// Update next InputResource in the cyclic list
	getNext<InputResource>()->ui.lock->setChecked(buy_equals_sell);
}

void InputResource::on_sell_price_valueChanged(const double sell_price) const {
	// Set sell price for resource, updating buy price if needed, and analyze if necessary
	items::setSellPrice(resource, sell_price);

	// Set buy price display to reflect up-to-date buy price
	// Will not call analyze again as no change is guaranteed
	ui.buy_price->setValue(resource->getBuyPrice());

	// Update next InputResource in the cyclic list
	getNext<InputResource>()->ui.sell_price->setValue(sell_price);
}

void InputResource::on_buy_price_valueChanged(const double buy_price) const {
	// Set buy price for resource and analyze if necessary
	items::setBuyPrice(resource, buy_price);

	// Update next InputResource in the cyclic list
	getNext<InputResource>()->ui.buy_price->setValue(buy_price);
}
