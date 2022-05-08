#pragma once

class StandingBonuses {
	public:
		StandingBonuses();
		StandingBonuses(double station_fee,
						double trading_tax);

		[[nodiscard]] double getStationFee() const;
		void setStationFee(double station_fee);

		[[nodiscard]] double getTradingTax() const;
		void setTradingTax(double trading_tax);

	private:
		double station_fee = 0;
		double trading_tax = 0;
};
