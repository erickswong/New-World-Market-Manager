#include "settings/standing_bonuses.h"

StandingBonuses::StandingBonuses() = default;

StandingBonuses::StandingBonuses(const float station_fee,
								 const float trading_tax)
									 : station_fee(station_fee),
                                       trading_tax(trading_tax) {
};

float StandingBonuses::getStationFee() const {
	return station_fee;
}

void StandingBonuses::setStationFee(const float station_fee) {
	this->station_fee = station_fee;
}

float StandingBonuses::getTradingTax() const {
	return trading_tax;
}

void StandingBonuses::setTradingTax(const float trading_tax) {
	this->trading_tax = trading_tax;
}
