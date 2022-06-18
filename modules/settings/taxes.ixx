export module settings:taxes;

import "json/json.h";

namespace settings::taxes {
	double trading_tax = 0.025;
	double crafting_fee = 0.5;
	double refining_fee = 0.5;

	// Resets members to default values
	export void reset() noexcept;

	// Sets members to values from json
	export void fromJson(Json::Value json_value);
	// Returns a json representing this namespace
	export [[nodiscard]] Json::Value toJson();

	export [[nodiscard]] double getTradingTax();
	export void setTradingTax(double trading_tax);

	export [[nodiscard]] double getCraftingFee();
	export void setCraftingFee(double crafting_fee);

	export [[nodiscard]] double getRefiningFee();
	export void setRefiningFee(double refining_fee);
};
