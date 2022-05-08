#include "settings/taxes.h"

Taxes::Taxes() = default;

Taxes::Taxes(const double trading_tax,
			 const double crafting_fee,
			 const double refining_fee)
				 : trading_tax(trading_tax),
                   crafting_fee(crafting_fee),
                   refining_fee(refining_fee) {
}

double Taxes::getTradingTax() const {
	return trading_tax;
}

void Taxes::setTradingTax(const double trading_tax) {
	this->trading_tax = trading_tax;
}

double Taxes::getCraftingFee() const {
	return crafting_fee;
}

void Taxes::setCraftingFee(const double crafting_fee) {
	this->crafting_fee = crafting_fee;
}

double Taxes::getRefiningFee() const {
	return refining_fee;
}

void Taxes::setRefiningFee(const double refining_fee) {
	this->refining_fee = refining_fee;
}
