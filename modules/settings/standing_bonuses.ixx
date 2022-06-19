export module settings:standing_bonuses;

import "json/json.h";

namespace settings::standing_bonuses {
	static constexpr double MIN_STATION_FEE = 0.;
	static constexpr double MAX_STATION_FEE = 65.28;
	static constexpr double MIN_TRADING_TAX = 0.;
	static constexpr double MAX_TRADING_TAX = 62.78;

	double station_fee = MIN_STATION_FEE;
	double trading_tax = MIN_TRADING_TAX;

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
