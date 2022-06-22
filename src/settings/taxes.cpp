module settings:taxes;

import exceptions;

namespace settings::taxes {
	void reset() noexcept {
		crafting_fee = MIN_CRAFTING_FEE;
		refining_fee = MIN_REFINING_FEE;
		trading_tax  = MIN_TRADING_TAX;
	}

	void fromJson(const Json::Value& json_value) {
		try {
			setCraftingFee(json_value["crafting_fee"].asDouble());
			setRefiningFee(json_value["refining_fee"].asDouble());
			setTradingTax(json_value["trading_tax"].asDouble());
		} catch (const std::exception& e) {
			throw BadJsonException("taxes is malformed", e);
		}
	}

	Json::Value toJson() {
		Json::Value json_value;

		json_value["crafting_fee"] = Json::Value(crafting_fee);
		json_value["refining_fee"] = Json::Value(refining_fee);
		json_value["trading_tax"]  = Json::Value(trading_tax);

		return json_value;
	}

	double getCraftingFee() {
		return crafting_fee;
	}

	void setCraftingFee(const double new_crafting_fee) {
		if (new_crafting_fee < MIN_CRAFTING_FEE) {
			throw BadValueException("crafting_fee cannot be less than MIN_CRAFTING_FEE");
		} else if (new_crafting_fee > MAX_CRAFTING_FEE) {
			throw BadValueException("crafting_fee cannot be greater than MAX_CRAFTING_FEE");
		}

		crafting_fee = new_crafting_fee;
	}

	double getRefiningFee() {
		return refining_fee;
	}

	void setRefiningFee(const double new_refining_fee) {
		if (new_refining_fee < MIN_REFINING_FEE) {
			throw BadValueException("refining_fee cannot be less than MIN_REFINING_FEE");
		} else if (new_refining_fee > MAX_REFINING_FEE) {
			throw BadValueException("refining_fee cannot be greater than MAX_REFINING_FEE");
		}

		refining_fee = new_refining_fee;
	}

	double getTradingTax() {
		return trading_tax;
	}

	void setTradingTax(const double new_trading_tax) {
		if (new_trading_tax < MIN_TRADING_TAX) {
			throw BadValueException("trading_tax cannot be less than MIN_TRADING_TAX");
		} else if (new_trading_tax > MAX_TRADING_TAX) {
			throw BadValueException("trading_tax cannot be greater than MAX_TRADING_TAX");
		}

		trading_tax = new_trading_tax;
	}
}
