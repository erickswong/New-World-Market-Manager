#include "settings/taxes.h"

Taxes::Taxes() = default;

Taxes::Taxes(const float trading_tax,
			 const float crafting_fee,
			 const float refining_fee)
				 : trading_tax(trading_tax),
                   crafting_fee(crafting_fee),
                   refining_fee(refining_fee) {
}

float Taxes::getTradingTax() const {
	return trading_tax;
}

void Taxes::setTradingTax(const float trading_tax) {
	this->trading_tax = trading_tax;
}

float Taxes::getCraftingFee() const {
	return crafting_fee;
}

void Taxes::setCraftingFee(const float crafting_fee) {
	this->crafting_fee = crafting_fee;
}

float Taxes::getRefiningFee() const {
	return refining_fee;
}

void Taxes::setRefiningFee(const float refining_fee) {
	this->refining_fee = refining_fee;
}
