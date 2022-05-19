#include "settings/settings.h"

#include <fstream>

Settings::Settings() = default;

Settings::Settings(TradeSkills trade_skills,
                   ArmourSets armour_sets,
                   Taxes taxes,
                   StandingBonuses standing_bonuses,
                   FortBonuses fort_bonuses)
	                   : trade_skills(trade_skills),
                         armour_sets(armour_sets),
                         taxes(taxes),
                         standing_bonuses(standing_bonuses),
                         fort_bonuses(fort_bonuses) {
}

Settings::Settings(Json::Value json_value)
	: trade_skills(json_value["trade_skills"]),
      armour_sets(json_value["armour_sets"]),
      taxes(json_value["taxes"]),
      standing_bonuses(json_value["standing_bonuses"]),
      fort_bonuses(json_value["fort_bonuses"]) {
}

void Settings::writeToDisk() const {
    std::ofstream file("data/settings.json");
    Json::StyledWriter styled_writer;

    file << styled_writer.write(getJsonValue());

    file.close();
}

Json::Value Settings::getJsonValue() const {
    Json::Value json_value;

    json_value["trade_skills"] = trade_skills.getJsonValue();
    json_value["armour_sets"] = armour_sets.getJsonValue();
    json_value["taxes"] = taxes.getJsonValue();
    json_value["standing_bonuses"] = standing_bonuses.getJsonValue();
    json_value["fort_bonuses"] = fort_bonuses.getJsonValue();

    return json_value;
}

double Settings::smeltingYieldBonus() const {
    return trade_skills.smeltingYieldBonus() + armour_sets.smeltingYieldBonus() + fort_bonuses.yieldBonus();
}

double Settings::woodworkingYieldBonus() const {
    return trade_skills.woodworkingYieldBonus() + armour_sets.woodworkingYieldBonus() + fort_bonuses.yieldBonus();
}

double Settings::leatherworkingYieldBonus() const {
    return trade_skills.leatherworkingYieldBonus() + armour_sets.leatherworkingYieldBonus() + fort_bonuses.yieldBonus();
}

double Settings::weavingYieldBonus() const {
    return trade_skills.weavingYieldBonus() + armour_sets.weavingYieldBonus() + fort_bonuses.yieldBonus();
}

double Settings::stonecuttingYieldBonus() const {
    return trade_skills.stonecuttingYieldBonus() + armour_sets.stonecuttingYieldBonus() + fort_bonuses.yieldBonus();
}

TradeSkills& Settings::getTradeSkills() {
    return trade_skills;
}

ArmourSets& Settings::getArmourSets() {
    return armour_sets;
}

Taxes& Settings::getTaxes() {
    return taxes;
}

StandingBonuses& Settings::getStandingBonuses() {
    return standing_bonuses;
}

FortBonuses& Settings::getFortBonuses() {
    return fort_bonuses;
}
