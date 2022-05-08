#pragma once

#include "armour_sets.h"
#include "taxes.h"
#include "standing_bonuses.h"
#include "fort_bonuses.h"

class Settings {
	public:
		Settings();
		Settings(ArmourSets* armour_sets,
		         Taxes* taxes,
		         StandingBonuses* standing_bonuses,
		         FortBonuses* fort_bonuses);
		~Settings();

		[[nodiscard]] ArmourSets* getArmourSets() const;
		[[nodiscard]] Taxes* getTaxes() const;
		[[nodiscard]] StandingBonuses* getStandingBonuses() const;
		[[nodiscard]] FortBonuses* getFortBonuses() const;

	private:
		ArmourSets* armour_sets;
		Taxes* taxes;
		StandingBonuses* standing_bonuses;
		FortBonuses* fort_bonuses;
};
