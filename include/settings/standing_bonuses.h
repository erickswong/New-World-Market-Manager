#pragma once

#include "jsoncpp/json/json.h"

class StandingBonuses {
	public:
		StandingBonuses();
		StandingBonuses(double station_fee,
						double trading_tax);
		explicit StandingBonuses(Json::Value json_value);

		[[nodiscard]] Json::Value getJsonValue() const;

		[[nodiscard]] double getStationFee() const;
		void setStationFee(double station_fee);

		[[nodiscard]] double getTradingTax() const;
		void setTradingTax(double trading_tax);

	private:
		double station_fee = 0.;
		double trading_tax = 0.;
};
