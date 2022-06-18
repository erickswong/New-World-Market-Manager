#include "ui/content_pages/input_pages/input_item.h"

InputItem::InputItem(const std::string& item_name, QWidget *parent)
	: QWidget(parent),
      item_name(item_name) {
	// Set up ui
	ui.setupUi(this);

	// Get item
	Item* item = items::at(item_name);

	// Set image
	ui.image->setPixmap(QPixmap(QString(item->getImagePath().c_str())));

	// Set label
	ui.label->setText(QCoreApplication::translate("InputItem", item->getItemName().c_str(), nullptr));

	// Set lock
	ui.lock->setChecked(item->getBuyEqualsSell());

	// Set sell price
	ui.sell_price->setValue(item->getSellPrice());

	// Set buy price
	ui.buy_price->setReadOnly(item->getBuyEqualsSell());
	ui.buy_price->setValue(item->getBuyPrice());
}

void InputItem::on_lock_clicked(const bool buy_equals_sell) const {
	// Get item
	Item* item = items::at(item_name);

	// Set buy equal sell for item, updating buy price if needed, and analyze if necessary
	items::setBuyEqualsSell(item, buy_equals_sell);

	// Set display to reflect buy equals sell state
	ui.buy_price->setReadOnly(buy_equals_sell);

	// Set buy price display to reflect up-to-date buy price
	// Will not call analyze again as no change is guaranteed
	ui.buy_price->setValue(item->getBuyPrice());
}

void InputItem::on_sell_price_valueChanged(const double sell_price) const {
	// Get item
	Item* item = items::at(item_name);

	// Set sell price for item, updating buy price if needed, and analyze if necessary
	items::setSellPrice(item, sell_price);

	// Set buy price display to reflect up-to-date buy price
	// Will not call analyze again as no change is guaranteed
	ui.buy_price->setValue(item->getBuyPrice());
}

void InputItem::on_buy_price_valueChanged(const double buy_price) const {
	// Get item
	Item* item = items::at(item_name);

	// Set buy price for item and analyze if necessary
	items::setBuyPrice(item, buy_price);
}
