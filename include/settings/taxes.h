#pragma once

class Taxes {
	public:
		Taxes();
		Taxes(float trading_tax,
			  float crafting_fee,
			  float refining_fee);

		[[nodiscard]] float getTradingTax() const;
		void setTradingTax(float trading_tax);

		[[nodiscard]] float getCraftingFee() const;
		void setCraftingFee(float crafting_fee);

		[[nodiscard]] float getRefiningFee() const;
		void setRefiningFee(float refining_fee);

	private:
		float trading_tax = 0.025f;
		float crafting_fee = 0.5f;
		float refining_fee = 0.5f;
};
