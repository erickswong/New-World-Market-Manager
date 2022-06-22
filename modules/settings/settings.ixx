export module settings;

export import :armour_sets;
export import :fort_bonuses;
export import :standing_bonuses;
export import :taxes;
export import :trade_skills;

import "json/json.h";

namespace settings {
	// Set up settings
	export void setUp();
	// Resets members to default values
	export void reset() noexcept;

	// Sets members to values from json
	export void fromJson(const Json::Value& json_value);
	// Returns a json representing this namespace
	export [[nodiscard]] Json::Value toJson();
	// Writes a json representing this namespace to disk
	export void writeToDisk();

	export [[nodiscard]] double smeltingYieldBonus();
	export [[nodiscard]] double woodworkingYieldBonus();
	export [[nodiscard]] double leatherworkingYieldBonus();
	export [[nodiscard]] double weavingYieldBonus();
	export [[nodiscard]] double stonecuttingYieldBonus();
	export [[nodiscard]] double fortYieldBonusMultiplier();

	// TODO: add tax calculator, may need parameter with base tax value
};
