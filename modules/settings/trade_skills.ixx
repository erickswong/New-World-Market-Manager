export module settings:trade_skills;

import "json/json.h";

namespace settings::trade_skills {
	static constexpr int MIN_TRADE_SKILL_LEVEL = 0;
	static constexpr int MAX_TRADE_SKILL_LEVEL = 200;
	static constexpr double LEVEL_YIELD_BONUS  = 0.001;

	int smelting_level       = MAX_TRADE_SKILL_LEVEL;
	int woodworking_level    = MAX_TRADE_SKILL_LEVEL;
	int leatherworking_level = MAX_TRADE_SKILL_LEVEL;
	int weaving_level        = MAX_TRADE_SKILL_LEVEL;
	int stonecutting_level   = MAX_TRADE_SKILL_LEVEL;

	// Resets members to default values
	export void reset() noexcept;

	// Sets members to values from json
	export void fromJson(Json::Value json_value);
	// Returns a json representing this namespace
	export [[nodiscard]] Json::Value toJson();

	export [[nodiscard]] double smeltingYieldBonus();
	export [[nodiscard]] double woodworkingYieldBonus();
	export [[nodiscard]] double leatherworkingYieldBonus();
	export [[nodiscard]] double weavingYieldBonus();
	export [[nodiscard]] double stonecuttingYieldBonus();

	export [[nodiscard]] int getSmeltingLevel();
	export void setSmeltingLevel(int smelting_level);

	export [[nodiscard]] int getWoodworkingLevel();
	export void setWoodworkingLevel(int woodworking_level);

	export [[nodiscard]] int getLeatherworkingLevel();
	export void setLeatherworkingLevel(int leatherworking_level);

	export [[nodiscard]] int getWeavingLevel();
	export void setWeavingLevel(int weaving_level);

	export [[nodiscard]] int getStonecuttingLevel();
	export void setStonecuttingLevel(int stonecutting_level);
};
