export module settings:fort_bonuses;

import "json/json.h";

namespace settings::fort_bonuses {
	static constexpr double FIRST_LIGHT_YIELD_BONUS = 0.1;
	static constexpr double WEAVERS_FEN_TAX_BONUS   = 0.1;

	bool has_first_light = false;
	bool has_weavers_fen = false;

	// Resets members to default values
	export void reset() noexcept;

	// Sets members to values from json
	export void fromJson(Json::Value json_value);
	// Returns a json representing this namespace
	export [[nodiscard]] Json::Value toJson();

	export [[nodiscard]] double yieldBonus();
	export [[nodiscard]] double taxBonus();

	export [[nodiscard]] bool getHasFirstLight();
	export void setHasFirstLight(bool new_has_first_light);

	export [[nodiscard]] bool getHasWeaversFen();
	export void setHasWeaversFen(bool new_has_weavers_fen);
};
