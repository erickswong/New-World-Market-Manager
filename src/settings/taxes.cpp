module settings:taxes;

import exceptions;

namespace settings::taxes {
	void reset() noexcept {
		trading_tax  = 0.025;
		crafting_fee = 0.5;
		refining_fee = 0.5;
	}

	void fromJson(Json::Value json_value) {
		try {
			setTradingTax(json_value["trading_tax"].asDouble());
			setCraftingFee(json_value["crafting_fee"].asDouble());
			setRefiningFee(json_value["refining_fee"].asDouble());
		} catch (const std::exception& e) {
			throw BadJsonException("taxes is malformed", e);
		}
	}

	Json::Value toJson() {
		Json::Value json_value;

		json_value["trading_tax"]  = Json::Value(trading_tax);
		json_value["crafting_fee"] = Json::Value(crafting_fee);
		json_value["refining_fee"] = Json::Value(refining_fee);

		return json_value;
	}

	double getTradingTax() {
		return trading_tax;
	}

	void setTradingTax(const double new_trading_tax) {
		if (new_trading_tax < 0.025) {
			throw BadValueException("trading_tax cannot be less than 0.025");
		} // TODO: throw exception if greater than upper bound

		trading_tax = new_trading_tax;
	}

	double getCraftingFee() {
		return crafting_fee;
	}

	void setCraftingFee(const double new_crafting_fee) {
		if (new_crafting_fee < 0.5) {
			throw BadValueException("crafting_fee cannot be less than 0.5");
		} // TODO: throw exception if greater than upper bound

		crafting_fee = new_crafting_fee;
	}

	double getRefiningFee() {
		return refining_fee;
	}

	void setRefiningFee(const double new_refining_fee) {
		if (new_refining_fee < 0.5) {
			throw BadValueException("refining_fee cannot be less than 0.5");
		} // TODO: throw exception if greater than upper bound

		refining_fee = new_refining_fee;
	}
}
