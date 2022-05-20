#include "settings/taxes.h"

Taxes::Taxes() = default;

Taxes::Taxes(const double trading_tax,
			 const double crafting_fee,
			 const double refining_fee)
				 : trading_tax(trading_tax),
                   crafting_fee(crafting_fee),
                   refining_fee(refining_fee) {
}

Taxes::Taxes(Json::Value json_value)
	: trading_tax(json_value["trading_tax"].asDouble()),
	  crafting_fee(json_value["crafting_fee"].asDouble()),
	  refining_fee(json_value["refining_fee"].asDouble()) {
	// TODO: add BadJsonExceptions for out of range values
}

Json::Value Taxes::toJson() const {
	Json::Value json_value;

	json_value["trading_tax"] = Json::Value(trading_tax);
	json_value["crafting_fee"] = Json::Value(crafting_fee);
	json_value["refining_fee"] = Json::Value(refining_fee);

	return json_value;
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
