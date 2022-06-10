module settings:armour_sets;

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

ArmourSets::ArmourSets(Json::Value json_value)
	: smelter_set(json_value["smelter_set"]),
      woodworker_set(json_value["woodworker_set"]),
      weaver_set(json_value["weaver_set"]),
      tanner_set(json_value["tanner_set"]),
      stonecutter_set(json_value["stonecutter_set"]) {
}

Json::Value ArmourSets::toJson() const {
    Json::Value json_value;

    json_value["smelter_set"] = smelter_set.toJson();
    json_value["woodworker_set"] = smelter_set.toJson();
    json_value["weaver_set"] = smelter_set.toJson();
    json_value["tanner_set"] = smelter_set.toJson();
    json_value["stonecutter_set"] = smelter_set.toJson();

    return json_value;
}

double ArmourSets::smeltingYieldBonus() const {
    return ARMOUR_YIELD_BONUS * smelter_set.numberAcquired();
}

double ArmourSets::woodworkingYieldBonus() const {
    return ARMOUR_YIELD_BONUS * woodworker_set.numberAcquired();
}

double ArmourSets::leatherworkingYieldBonus() const {
    return ARMOUR_YIELD_BONUS * weaver_set.numberAcquired();
}

double ArmourSets::weavingYieldBonus() const {
    return ARMOUR_YIELD_BONUS * tanner_set.numberAcquired();
}

double ArmourSets::stonecuttingYieldBonus() const {
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
