#pragma once

#include "armour_set.h"

class ArmourSets {
	public:
		ArmourSets();
		ArmourSets(ArmourSet smelter_set,
		           ArmourSet woodworker_set,
		           ArmourSet weaver_set,
		           ArmourSet tanner_set,
		           ArmourSet stonecutter_set);

		[[nodiscard]] float smeltingYieldBonus() const;
		[[nodiscard]] float woodworkingYieldBonus() const;
		[[nodiscard]] float leatherworkingYieldBonus() const;
		[[nodiscard]] float weavingYieldBonus() const;
		[[nodiscard]] float stonecuttingYieldBonus() const;

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
