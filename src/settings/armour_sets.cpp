#include "settings/armour_sets.h"

ArmourSets::ArmourSets() : smelter_set(new ArmourSet),
                           woodworker_set(new ArmourSet),
                           weaver_set(new ArmourSet),
                           tanner_set(new ArmourSet),
                           stonecutter_set(new ArmourSet) {
}

ArmourSets::ArmourSets(ArmourSet* smelter_set,
                       ArmourSet* woodworker_set,
                       ArmourSet* weaver_set,
                       ArmourSet* tanner_set,
                       ArmourSet* stonecutter_set)
	                       : smelter_set(smelter_set),
                             woodworker_set(woodworker_set),
                             weaver_set(weaver_set),
                             tanner_set(tanner_set),
                             stonecutter_set(stonecutter_set) {
}

ArmourSets::~ArmourSets() {
    delete smelter_set;
    delete woodworker_set;
    delete weaver_set;
    delete tanner_set;
    delete stonecutter_set;
}

ArmourSet* ArmourSets::getSmelterSet() const {
    return smelter_set;
}

ArmourSet* ArmourSets::getWoodworkerSet() const {
    return woodworker_set;
}

ArmourSet* ArmourSets::getWeaverSet() const {
    return weaver_set;
}

ArmourSet* ArmourSets::getTannerSet() const {
    return tanner_set;
}

ArmourSet* ArmourSets::getStonecutterSet() const {
    return stonecutter_set;
}
