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
