#pragma once

#include "armour_set.h"

class ArmourSets {
	public:
		ArmourSets();
		ArmourSets(ArmourSet* smelter_set,
		           ArmourSet* woodworker_set,
		           ArmourSet* weaver_set,
		           ArmourSet* tanner_set,
		           ArmourSet* stonecutter_set);
		~ArmourSets();

		[[nodiscard]] ArmourSet* getSmelterSet() const;
		[[nodiscard]] ArmourSet* getWoodworkerSet() const;
		[[nodiscard]] ArmourSet* getWeaverSet() const;
		[[nodiscard]] ArmourSet* getTannerSet() const;
		[[nodiscard]] ArmourSet* getStonecutterSet() const;

	private:
		ArmourSet* smelter_set;
		ArmourSet* woodworker_set;
		ArmourSet* weaver_set;
		ArmourSet* tanner_set;
		ArmourSet* stonecutter_set;
};
