#include "settings/settings.h"

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
