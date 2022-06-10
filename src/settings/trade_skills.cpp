module settings:trade_skills;

import exceptions;

TradeSkills::TradeSkills() = default;

TradeSkills::TradeSkills(const int smelting_level,
                         const int woodworking_level,
                         const int leatherworking_level,
                         const int weaving_level,
                         const int stonecutting_level)
	                         : smelting_level(smelting_level),
                               woodworking_level(woodworking_level),
                               leatherworking_level(leatherworking_level),
                               weaving_level(weaving_level),
                               stonecutting_level(stonecutting_level) {
}

TradeSkills::TradeSkills(Json::Value json_value)
	: smelting_level(json_value["smelting_level"].asInt()),
      woodworking_level(json_value["woodworking_level"].asInt()),
      leatherworking_level(json_value["leatherworking_level"].asInt()),
      weaving_level(json_value["weaving_level"].asInt()),
      stonecutting_level(json_value["stonecutting_level"].asInt()) {
    // Check that values satisfy constraints TODO: abstract to own functions, to be used in setters as well
    if (smelting_level < 0 || smelting_level > 200) {
        throw BadJsonException("Invalid smelting_level in settings.json");
    }
    if (woodworking_level < 0 || woodworking_level > 200) {
        throw BadJsonException("Invalid woodworking_level in settings.json");
    }
    if (leatherworking_level < 0 || leatherworking_level > 200) {
        throw BadJsonException("Invalid leatherworking_level in settings.json");
    }
    if (weaving_level < 0 || weaving_level > 200) {
        throw BadJsonException("Invalid weaving_level in settings.json");
    }
    if (stonecutting_level < 0 || stonecutting_level > 200) {
        throw BadJsonException("Invalid stonecutting_level in settings.json");
    }
}

Json::Value TradeSkills::toJson() const {
    Json::Value json_value;

    json_value["smelting_level"] = Json::Value(smelting_level);
    json_value["woodworking_level"] = Json::Value(woodworking_level);
    json_value["leatherworking_level"] = Json::Value(leatherworking_level);
    json_value["weaving_level"] = Json::Value(weaving_level);
    json_value["stonecutting_level"] = Json::Value(stonecutting_level);

    return json_value;
}

double TradeSkills::smeltingYieldBonus() const {
    return LEVEL_YIELD_BONUS * smelting_level;
}

double TradeSkills::woodworkingYieldBonus() const {
    return LEVEL_YIELD_BONUS * woodworking_level;
}

double TradeSkills::leatherworkingYieldBonus() const {
    return LEVEL_YIELD_BONUS * leatherworking_level;
}

double TradeSkills::weavingYieldBonus() const {
    return LEVEL_YIELD_BONUS * weaving_level;
}

double TradeSkills::stonecuttingYieldBonus() const {
    return LEVEL_YIELD_BONUS * stonecutting_level;
}

int TradeSkills::getSmeltingLevel() const {
    return smelting_level;
}

void TradeSkills::setSmeltingLevel(int smelting_level) {
    this->smelting_level = smelting_level;
}

int TradeSkills::getWoodworkingLevel() const {
    return woodworking_level;
}

void TradeSkills::setWoodworkingLevel(int woodworking_level) {
    this->woodworking_level = woodworking_level;
}

int TradeSkills::getLeatherworkingLevel() const {
    return leatherworking_level;
}

void TradeSkills::setLeatherworkingLevel(int leatherworking_level) {
    this->leatherworking_level = leatherworking_level;
}

int TradeSkills::getWeavingLevel() const {
    return weaving_level;
}

void TradeSkills::setWeavingLevel(int weaving_level) {
    this->weaving_level = weaving_level;
}

int TradeSkills::getStonecuttingLevel() const {
    return stonecutting_level;
}

void TradeSkills::setStonecuttingLevel(int stonecutting_level) {
    this->stonecutting_level = stonecutting_level;
}
