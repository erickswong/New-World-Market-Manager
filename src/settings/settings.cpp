#include "settings/settings.h"

#include <filesystem>
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
    // Create data directory if missing
    std::filesystem::create_directory("data");

    // Create settings.json file
    std::ofstream file("data/settings.json");

    // Write json into file
    Json::StyledWriter styled_writer;
    file << styled_writer.write(toJson());

    // Close file
    file.close();
}

Json::Value Settings::toJson() const {
    Json::Value json_value;

    json_value["trade_skills"] = trade_skills.toJson();
    json_value["armour_sets"] = armour_sets.toJson();
    json_value["taxes"] = taxes.toJson();
    json_value["standing_bonuses"] = standing_bonuses.toJson();
    json_value["fort_bonuses"] = fort_bonuses.toJson();

    return json_value;
}

double Settings::smeltingYieldBonus() const {
    return trade_skills.smeltingYieldBonus() + armour_sets.smeltingYieldBonus();
}

double Settings::woodworkingYieldBonus() const {
    return trade_skills.woodworkingYieldBonus() + armour_sets.woodworkingYieldBonus();
}

double Settings::leatherworkingYieldBonus() const {
    return trade_skills.leatherworkingYieldBonus() + armour_sets.leatherworkingYieldBonus();
}

double Settings::weavingYieldBonus() const {
    return trade_skills.weavingYieldBonus() + armour_sets.weavingYieldBonus();
}

double Settings::stonecuttingYieldBonus() const {
    return trade_skills.stonecuttingYieldBonus() + armour_sets.stonecuttingYieldBonus();
}

double Settings::fortYieldBonusMultiplier() const {
    return 1. + fort_bonuses.yieldBonus();
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
