#include "settings/settings.h"

Settings::Settings() : armour_sets(new ArmourSets),
                       taxes(new Taxes),
                       standing_bonuses(new StandingBonuses),
                       fort_bonuses(new FortBonuses) {
};

Settings::Settings(ArmourSets* armour_sets,
                   Taxes* taxes,
                   StandingBonuses* standing_bonuses,
                   FortBonuses* fort_bonuses)
	                   : armour_sets(armour_sets),
                         taxes(taxes),
                         standing_bonuses(standing_bonuses),
                         fort_bonuses(fort_bonuses) {
}

Settings::~Settings() {
    delete armour_sets;
    delete taxes;
    delete standing_bonuses;
    delete fort_bonuses;
}

ArmourSets* Settings::getArmourSets() const {
    return armour_sets;
}

Taxes* Settings::getTaxes() const {
    return taxes;
}

StandingBonuses* Settings::getStandingBonuses() const {
    return standing_bonuses;
}

FortBonuses* Settings::getFortBonuses() const {
    return fort_bonuses;
}
