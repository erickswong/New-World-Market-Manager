export module settings:armour_sets;

export import :armour_set;

import "json/json.h";

namespace settings::armour_sets {
	static constexpr double ARMOUR_YIELD_BONUS = 0.02;

	ArmourSet smelter_set;
	ArmourSet woodworker_set;
	ArmourSet weaver_set;
	ArmourSet tanner_set;
	ArmourSet stonecutter_set;

	// Resets members to default values
	export void reset() noexcept;

	// Sets members to values from json
	export void fromJson(const Json::Value& json_value);
	// Returns a json representing this namespace
	export [[nodiscard]] Json::Value toJson();

	export [[nodiscard]] double smeltingYieldBonus();
	export [[nodiscard]] double woodworkingYieldBonus();
	export [[nodiscard]] double leatherworkingYieldBonus();
	export [[nodiscard]] double weavingYieldBonus();
	export [[nodiscard]] double stonecuttingYieldBonus();

	export ArmourSet& getSmelterSet();
	export ArmourSet& getWoodworkerSet();
	export ArmourSet& getWeaverSet();
	export ArmourSet& getTannerSet();
	export ArmourSet& getStonecutterSet();
};
