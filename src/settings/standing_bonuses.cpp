module settings:standing_bonuses;

StandingBonuses::StandingBonuses() = default;

StandingBonuses::StandingBonuses(const double station_fee,
								 const double trading_tax)
									 : station_fee(station_fee),
                                       trading_tax(trading_tax) {
}

StandingBonuses::StandingBonuses(Json::Value json_value)
	: station_fee(json_value["station_fee"].asDouble()),
      trading_tax(json_value["trading_tax"].asDouble()) {
	// TODO: add BadJsonExceptions for out of range values
}

Json::Value StandingBonuses::toJson() const {
	Json::Value json_value;

	json_value["station_fee"] = Json::Value(station_fee);
	json_value["trading_tax"] = Json::Value(trading_tax);

	return json_value;
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
