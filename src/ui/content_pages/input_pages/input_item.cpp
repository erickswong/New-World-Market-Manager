#include "ui/content_pages/input_pages/input_item.h"

InputItem::InputItem(Item* item, QWidget *parent)
	: QWidget(parent),
      item(item)
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
	ui.buy_price->setValue(item->getBuyPrice());
}

void InputItem::on_lock_clicked(const bool buy_equals_sell) const {
	item->setBuyEqualsSell(buy_equals_sell);

	ui.buy_price->setValue(item->getBuyPrice());
}

void InputItem::on_sell_price_valueChanged(const double sell_price) const {
	item->setSellPrice(sell_price);

	if (item->getBuyEqualsSell()) {
		ui.buy_price->setValue(item->getBuyPrice());
	}
}

void InputItem::on_buy_price_valueChanged(const double buy_price) const {
	item->setBuyPrice(buy_price);
}
