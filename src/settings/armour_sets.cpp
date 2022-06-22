module settings:armour_sets;

import exceptions;

namespace settings::armour_sets {
    void reset() noexcept {
        smelter_set.reset();
        woodworker_set.reset();
        weaver_set.reset();
        tanner_set.reset();
        stonecutter_set.reset();
    }

    void fromJson(const Json::Value& json_value) {
        try {
            smelter_set.fromJson(json_value["smelter_set"], "smelter_set");
            woodworker_set.fromJson(json_value["woodworker_set"], "woodworker_set");
            weaver_set.fromJson(json_value["weaver_set"], "weaver_set");
            tanner_set.fromJson(json_value["tanner_set"], "tanner_set");
            stonecutter_set.fromJson(json_value["stonecutter_set"], "stonecutter_set");
        } catch (const std::exception& e) {
            throw BadJsonException("armour_sets is malformed", e);
        }
    }

    Json::Value toJson() {
        Json::Value json_value;

        json_value["smelter_set"]     = smelter_set.toJson();
        json_value["woodworker_set"]  = woodworker_set.toJson();
        json_value["weaver_set"]      = weaver_set.toJson();
        json_value["tanner_set"]      = tanner_set.toJson();
        json_value["stonecutter_set"] = stonecutter_set.toJson();

        return json_value;
    }

    double smeltingYieldBonus() {
        return ARMOUR_YIELD_BONUS * smelter_set.numberAcquired();
    }

    double woodworkingYieldBonus() {
        return ARMOUR_YIELD_BONUS * woodworker_set.numberAcquired();
    }

    double leatherworkingYieldBonus() {
        return ARMOUR_YIELD_BONUS * weaver_set.numberAcquired();
    }

    double weavingYieldBonus() {
        return ARMOUR_YIELD_BONUS * tanner_set.numberAcquired();
    }

    double stonecuttingYieldBonus() {
        return ARMOUR_YIELD_BONUS * stonecutter_set.numberAcquired();
    }

    ArmourSet& getSmelterSet() {
        return smelter_set;
    }

    ArmourSet& getWoodworkerSet() {
        return woodworker_set;
    }

    ArmourSet& getWeaverSet() {
        return weaver_set;
    }

    ArmourSet& getTannerSet() {
        return tanner_set;
    }

    ArmourSet& getStonecutterSet() {
        return stonecutter_set;
    }
}
