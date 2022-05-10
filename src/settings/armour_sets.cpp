#include "settings/armour_sets.h"

ArmourSets::ArmourSets() = default;

ArmourSets::ArmourSets(const ArmourSet smelter_set,
                       const ArmourSet woodworker_set,
                       const ArmourSet weaver_set,
                       const ArmourSet tanner_set,
                       const ArmourSet stonecutter_set)
	                       : smelter_set(smelter_set),
                             woodworker_set(woodworker_set),
                             weaver_set(weaver_set),
                             tanner_set(tanner_set),
                             stonecutter_set(stonecutter_set) {
}

ArmourSet& ArmourSets::getSmelterSet() {
    return smelter_set;
}

ArmourSet& ArmourSets::getWoodworkerSet() {
    return woodworker_set;
}

ArmourSet& ArmourSets::getWeaverSet() {
    return weaver_set;
}

ArmourSet& ArmourSets::getTannerSet() {
    return tanner_set;
}

ArmourSet& ArmourSets::getStonecutterSet() {
    return stonecutter_set;
}
