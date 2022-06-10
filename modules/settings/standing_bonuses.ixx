export module settings:standing_bonuses;

import "json/json.h";

export class StandingBonuses {
	public:
		StandingBonuses();
		StandingBonuses(double station_fee,
						double trading_tax);
		explicit StandingBonuses(Json::Value json_value);

		[[nodiscard]] Json::Value toJson() const;

		[[nodiscard]] double getStationFee() const;
		void setStationFee(double station_fee);

		[[nodiscard]] double getTradingTax() const;
		void setTradingTax(double trading_tax);

	private:
		double station_fee = 0.;
		double trading_tax = 0.;
};
