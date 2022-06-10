export module settings:armour_sets;

export import :armour_set;

import "json/json.h";

static constexpr double ARMOUR_YIELD_BONUS = 0.02;

export class ArmourSets {
	public:
		ArmourSets();
		ArmourSets(ArmourSet smelter_set,
				   ArmourSet woodworker_set,
				   ArmourSet weaver_set,
				   ArmourSet tanner_set,
				   ArmourSet stonecutter_set);
		explicit ArmourSets(Json::Value json_value);

		[[nodiscard]] Json::Value toJson() const;

		[[nodiscard]] double smeltingYieldBonus() const;
		[[nodiscard]] double woodworkingYieldBonus() const;
		[[nodiscard]] double leatherworkingYieldBonus() const;
		[[nodiscard]] double weavingYieldBonus() const;
		[[nodiscard]] double stonecuttingYieldBonus() const;

		ArmourSet& getSmelterSet();
		ArmourSet& getWoodworkerSet();
		ArmourSet& getWeaverSet();
		ArmourSet& getTannerSet();
		ArmourSet& getStonecutterSet();

	private:
		ArmourSet smelter_set;
		ArmourSet woodworker_set;
		ArmourSet weaver_set;
		ArmourSet tanner_set;
		ArmourSet stonecutter_set;
};
