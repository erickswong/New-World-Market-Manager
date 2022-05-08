#include "settings/standing_bonuses.h"

StandingBonuses::StandingBonuses() = default;

StandingBonuses::StandingBonuses(const double station_fee,
								 const double trading_tax)
									 : station_fee(station_fee),
                                       trading_tax(trading_tax) {
};

double StandingBonuses::getStationFee() const {
	return station_fee;
}

void StandingBonuses::setStationFee(const double station_fee) {
	this->station_fee = station_fee;
}

double StandingBonuses::getTradingTax() const {
	return trading_tax;
}

void StandingBonuses::setTradingTax(const double trading_tax) {
	this->trading_tax = trading_tax;
}
