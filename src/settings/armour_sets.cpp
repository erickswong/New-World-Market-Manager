#include "settings/armour_sets.h"

#include "constants.h"

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

float ArmourSets::smeltingYieldBonus() const {
    return ARMOUR_YIELD_BONUS * smelter_set.numberAcquired();
}

float ArmourSets::woodworkingYieldBonus() const {
    return ARMOUR_YIELD_BONUS * woodworker_set.numberAcquired();
}

float ArmourSets::leatherworkingYieldBonus() const {
    return ARMOUR_YIELD_BONUS * weaver_set.numberAcquired();
}

float ArmourSets::weavingYieldBonus() const {
    return ARMOUR_YIELD_BONUS * tanner_set.numberAcquired();
}

float ArmourSets::stonecuttingYieldBonus() const {
    return ARMOUR_YIELD_BONUS * stonecutter_set.numberAcquired();
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
