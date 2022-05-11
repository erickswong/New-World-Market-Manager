#pragma once

class StandingBonuses {
	public:
		StandingBonuses();
		StandingBonuses(float station_fee,
						float trading_tax);

		[[nodiscard]] float getStationFee() const;
		void setStationFee(float station_fee);

		[[nodiscard]] float getTradingTax() const;
		void setTradingTax(float trading_tax);

	private:
		float station_fee = 0.f;
		float trading_tax = 0.f;
};
