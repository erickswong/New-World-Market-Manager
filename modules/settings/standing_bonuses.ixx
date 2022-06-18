export module settings:standing_bonuses;

import "json/json.h";

namespace settings::standing_bonuses {
	double station_fee = 0.;
	double trading_tax = 0.;

	// Resets members to default values
	export void reset() noexcept;

	// Sets members to values from json
	export void fromJson(Json::Value json_value);
	// Returns a json representing this namespace
	export [[nodiscard]] Json::Value toJson();

	export [[nodiscard]] double getStationFee();
	export void setStationFee(double new_station_fee);

	export [[nodiscard]] double getTradingTax();
	export void setTradingTax(double new_trading_tax);
};
