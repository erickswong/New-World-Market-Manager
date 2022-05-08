#pragma once

class Taxes {
	public:
		Taxes();
		Taxes(double trading_tax,
			  double crafting_fee,
			  double refining_fee);

		[[nodiscard]] double getTradingTax() const;
		void setTradingTax(double trading_tax);

		[[nodiscard]] double getCraftingFee() const;
		void setCraftingFee(double crafting_fee);

		[[nodiscard]] double getRefiningFee() const;
		void setRefiningFee(double refining_fee);

	private:
		double trading_tax = 0.025;
		double crafting_fee = 0.5;
		double refining_fee = 0.5;
};
