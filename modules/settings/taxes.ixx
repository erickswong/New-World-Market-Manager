export module settings:taxes;

import "json/json.h";

namespace settings::taxes {
	static constexpr double MIN_CRAFTING_FEE = 0.5;
	static constexpr double MAX_CRAFTING_FEE = 3.;
	static constexpr double MIN_REFINING_FEE = 0.5;
	static constexpr double MAX_REFINING_FEE = 3.;
	static constexpr double MIN_TRADING_TAX  = 0.025;
	static constexpr double MAX_TRADING_TAX  = 0.25;

	double crafting_fee = MIN_CRAFTING_FEE;
	double refining_fee = MIN_REFINING_FEE;
	double trading_tax  = MIN_TRADING_TAX;

	// Resets members to default values
	export void reset() noexcept;

	// Sets members to values from json
	export void fromJson(const Json::Value& json_value);
	// Returns a json representing this namespace
	export [[nodiscard]] Json::Value toJson();

	export [[nodiscard]] double getCraftingFee();
	export void setCraftingFee(double crafting_fee);

	export [[nodiscard]] double getRefiningFee();
	export void setRefiningFee(double refining_fee);

	export [[nodiscard]] double getTradingTax();
	export void setTradingTax(double trading_tax);
};
