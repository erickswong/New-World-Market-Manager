module settings:fort_bonuses;

import exceptions;

namespace settings::fort_bonuses {
	void reset() noexcept {
		has_first_light = false;
		has_weavers_fen = false;
	}

	void fromJson(Json::Value json_value) {
		try {
			has_first_light = json_value["has_first_light"].asBool();
			has_weavers_fen = json_value["has_weavers_fen"].asBool();
		} catch (const std::exception& e) {
			throw BadJsonException("fort_bonuses is malformed", e);
		}
	}

	Json::Value toJson() {
		Json::Value json_value;

		json_value["has_first_light"] = Json::Value(has_first_light);
		json_value["has_weavers_fen"] = Json::Value(has_weavers_fen);

		return json_value;
	}

	double yieldBonus() {
		return FIRST_LIGHT_YIELD_BONUS * has_first_light;
	}

	double taxBonus() {
		return WEAVERS_FEN_TAX_BONUS * has_weavers_fen;
	}

	bool getHasFirstLight() {
		return has_first_light;
	}

	void setHasFirstLight(const bool new_has_first_light) {
		has_first_light = new_has_first_light;
	}

	bool getHasWeaversFen() {
		return  has_weavers_fen;
	}

	void setHasWeaversFen(const bool new_has_weavers_fen) {
		has_weavers_fen = new_has_weavers_fen;
	}
}
