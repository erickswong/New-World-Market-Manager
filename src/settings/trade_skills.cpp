module settings:trade_skills;

import exceptions;

namespace settings::trade_skills {
    void reset() noexcept {
        smelting_level       = MAX_TRADE_SKILL_LEVEL;
        woodworking_level    = MAX_TRADE_SKILL_LEVEL;
        leatherworking_level = MAX_TRADE_SKILL_LEVEL;
        weaving_level        = MAX_TRADE_SKILL_LEVEL;
        stonecutting_level   = MAX_TRADE_SKILL_LEVEL;
    }

    void fromJson(Json::Value json_value) {
        try {
            setSmeltingLevel(json_value["smelting_level"].asInt());
            setWoodworkingLevel(json_value["woodworking_level"].asInt());
            setLeatherworkingLevel(json_value["leatherworking_level"].asInt());
            setWeavingLevel(json_value["weaving_level"].asInt());
            setStonecuttingLevel(json_value["stonecutting_level"].asInt());
        } catch (const std::exception& e) {
            throw BadJsonException("trade_skills is malformed", e);
        }
    }

    Json::Value toJson() {
        Json::Value json_value;

        json_value["smelting_level"]       = Json::Value(smelting_level);
        json_value["woodworking_level"]    = Json::Value(woodworking_level);
        json_value["leatherworking_level"] = Json::Value(leatherworking_level);
        json_value["weaving_level"]        = Json::Value(weaving_level);
        json_value["stonecutting_level"]   = Json::Value(stonecutting_level);

        return json_value;
    }

    double smeltingYieldBonus() {
        return LEVEL_YIELD_BONUS * smelting_level;
    }

    double woodworkingYieldBonus() {
        return LEVEL_YIELD_BONUS * woodworking_level;
    }

    double leatherworkingYieldBonus() {
        return LEVEL_YIELD_BONUS * leatherworking_level;
    }

    double weavingYieldBonus() {
        return LEVEL_YIELD_BONUS * weaving_level;
    }

    double stonecuttingYieldBonus() {
        return LEVEL_YIELD_BONUS * stonecutting_level;
    }

    int getSmeltingLevel() {
        return smelting_level;
    }

    void setSmeltingLevel(int new_smelting_level) {
        if (new_smelting_level < MIN_TRADE_SKILL_LEVEL) {
            throw BadValueException("smelting_level cannot be less than MIN_TRADE_SKILL_LEVEL");
        } else if (new_smelting_level > MAX_TRADE_SKILL_LEVEL) {
            throw BadValueException("smelting_level cannot be greater than MAX_TRADE_SKILL_LEVEL");
        }

        smelting_level = new_smelting_level;
    }

    int getWoodworkingLevel() {
        return woodworking_level;
    }

    void setWoodworkingLevel(int new_woodworking_level) {
        if (new_woodworking_level < MIN_TRADE_SKILL_LEVEL) {
            throw BadValueException("woodworking_level cannot be less than MIN_TRADE_SKILL_LEVEL");
        } else if (new_woodworking_level > MAX_TRADE_SKILL_LEVEL) {
            throw BadValueException("woodworking_level cannot be greater than MAX_TRADE_SKILL_LEVEL");
        }

        woodworking_level = new_woodworking_level;
    }

    int getLeatherworkingLevel() {
        return leatherworking_level;
    }

    void setLeatherworkingLevel(int new_leatherworking_level) {
        if (new_leatherworking_level < MIN_TRADE_SKILL_LEVEL) {
            throw BadValueException("leatherworking_level cannot be less than MIN_TRADE_SKILL_LEVEL");
        } else if (new_leatherworking_level > MAX_TRADE_SKILL_LEVEL) {
            throw BadValueException("leatherworking_level cannot be greater than MAX_TRADE_SKILL_LEVEL");
        }

        leatherworking_level = new_leatherworking_level;
    }

    int getWeavingLevel() {
        return weaving_level;
    }

    void setWeavingLevel(int new_weaving_level) {
        if (new_weaving_level < MIN_TRADE_SKILL_LEVEL) {
            throw BadValueException("weaving_level cannot be less than MIN_TRADE_SKILL_LEVEL");
        } else if (new_weaving_level > MAX_TRADE_SKILL_LEVEL) {
            throw BadValueException("weaving_level cannot be greater than MAX_TRADE_SKILL_LEVEL");
        }

        weaving_level = new_weaving_level;
    }

    int getStonecuttingLevel() {
        return stonecutting_level;
    }

    void setStonecuttingLevel(int new_stonecutting_level) {
        if (new_stonecutting_level < MIN_TRADE_SKILL_LEVEL) {
            throw BadValueException("stonecutting_level cannot be less than MIN_TRADE_SKILL_LEVEL");
        } else if (new_stonecutting_level > MAX_TRADE_SKILL_LEVEL) {
            throw BadValueException("stonecutting_level cannot be greater than MAX_TRADE_SKILL_LEVEL");
        }

        stonecutting_level = new_stonecutting_level;
    }
}
