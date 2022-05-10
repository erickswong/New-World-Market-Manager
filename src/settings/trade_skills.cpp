#include "settings/trade_skills.h"

#include "constants.h"

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
