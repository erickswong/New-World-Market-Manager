#include "ui/content_pages/input_pages/input_item.h"

InputItem::InputItem(Item* item, Items* items, Settings* settings, QWidget *parent)
	: QWidget(parent),
      item(item),
      items(items),
      settings(settings)
{
	ui.setupUi(this);

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

void InputItem::setItems(Items* items) {
	this->items = items;

	// Set items for all children
	// No children
}

void InputItem::setSettings(Settings* settings) {
	this->settings = settings;

	// Set settings for all children
	// No children
}

void InputItem::on_lock_clicked(const bool buy_equals_sell) const {
	items->setBuyEqualsSell(item, buy_equals_sell, settings);

	ui.buy_price->setReadOnly(buy_equals_sell);
	ui.buy_price->setValue(item->getBuyPrice());
}

void InputItem::on_sell_price_valueChanged(const double sell_price) const {
	if (item->getBuyEqualsSell()) {
		item->setSellPrice(sell_price);
		ui.buy_price->setValue(item->getBuyPrice());
	} else {
		items->setSellPrice(item, sell_price, settings);
	}
}

void InputItem::on_buy_price_valueChanged(const double buy_price) const {
	items->setBuyPrice(item, buy_price, settings);
}
