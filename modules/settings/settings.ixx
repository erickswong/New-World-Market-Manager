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

	// TODO: add tax calculator, may need parameter with base tax value
	// TODO: 30% tax discount for governing company members

	// Returns the yield bonus for smelting
	export [[nodiscard]] double smeltingYieldBonus();
	// Returns the yield bonus for woodworking
	export [[nodiscard]] double woodworkingYieldBonus();
	// Returns the yield bonus for leatherworking
	export [[nodiscard]] double leatherworkingYieldBonus();
	// Returns the yield bonus for weaving
	export [[nodiscard]] double weavingYieldBonus();
	// Returns the yield bonus for stonecutting
	export [[nodiscard]] double stonecuttingYieldBonus();
};
