#pragma once

#include "armour_sets.h"
#include "fort_bonuses.h"
#include "standing_bonuses.h"
#include "taxes.h"
#include "trade_skills.h"

class Settings {
	public:
		Settings();
		Settings(TradeSkills trade_skills,
				 ArmourSets armour_sets,
		         Taxes taxes,
		         StandingBonuses standing_bonuses,
		         FortBonuses fort_bonuses);

		[[nodiscard]] double smeltingYieldBonus() const;
		[[nodiscard]] double woodworkingYieldBonus() const;
		[[nodiscard]] double leatherworkingYieldBonus() const;
		[[nodiscard]] double weavingYieldBonus() const;
		[[nodiscard]] double stonecuttingYieldBonus() const;

		// TODO: add tax calculator, may need parameter with base tax value

		TradeSkills& getTradeSkills();
		ArmourSets& getArmourSets();
		Taxes& getTaxes();
		StandingBonuses& getStandingBonuses();
		FortBonuses& getFortBonuses();

	private:
		TradeSkills trade_skills;
		ArmourSets armour_sets;
		Taxes taxes;
		StandingBonuses standing_bonuses;
		FortBonuses fort_bonuses;
};
