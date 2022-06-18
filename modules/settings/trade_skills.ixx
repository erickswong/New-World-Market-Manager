export module settings:trade_skills;

import "json/json.h";

static constexpr double LEVEL_YIELD_BONUS = 0.001;

namespace settings::trade_skills {
	int smelting_level = 200;
	int woodworking_level = 200;
	int leatherworking_level = 200;
	int weaving_level = 200;
	int stonecutting_level = 200;

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
