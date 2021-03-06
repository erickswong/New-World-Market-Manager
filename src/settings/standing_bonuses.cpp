module settings:standing_bonuses;

import exceptions;

namespace settings::standing_bonuses {
	void reset() noexcept {
		station_fee = MIN_STATION_FEE;
		trading_tax = MIN_TRADING_TAX;
	}

	void fromJson(const Json::Value& json_value) {
		try {
			setStationFee(json_value["station_fee"].asDouble());
			setTradingTax(json_value["trading_tax"].asDouble());
		} catch (const std::exception& e) {
			throw BadJsonException("standing_bonuses is malformed", e);
		}
	}

	Json::Value toJson() {
		Json::Value json_value;

		json_value["station_fee"] = Json::Value(station_fee);
		json_value["trading_tax"] = Json::Value(trading_tax);

		return json_value;
	}

	double getStationFee() {
		return station_fee;
	}

	void setStationFee(const double new_station_fee) {
		if (new_station_fee < MIN_STATION_FEE) {
			throw BadValueException("station_fee cannot be less than MIN_STATION_FEE");
		} else if (new_station_fee > MAX_STATION_FEE) {
			throw BadValueException("station_fee cannot be greather than MAX_STATION_FEE");
		}

		station_fee = new_station_fee;
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
