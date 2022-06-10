export module settings;

export import :armour_sets;
export import :fort_bonuses;
export import :standing_bonuses;
export import :taxes;
export import :trade_skills;

import "json/json.h";

// Forward declaration
class Settings;

namespace settings {
	// Initializes Settings and returns a pointer to it
	export Settings* init();
};

export class Settings {
	public:
		Settings();
		explicit Settings(Json::Value json_value);

		void writeToDisk() const;
		[[nodiscard]] Json::Value toJson() const;

		[[nodiscard]] double smeltingYieldBonus() const;
		[[nodiscard]] double woodworkingYieldBonus() const;
		[[nodiscard]] double leatherworkingYieldBonus() const;
		[[nodiscard]] double weavingYieldBonus() const;
		[[nodiscard]] double stonecuttingYieldBonus() const;
		[[nodiscard]] double fortYieldBonusMultiplier() const;

		// TODO: add tax calculator, may need parameter with base tax value

		[[nodiscard]] TradeSkills& getTradeSkills();
		[[nodiscard]] ArmourSets& getArmourSets();
		[[nodiscard]] Taxes& getTaxes();
		[[nodiscard]] StandingBonuses& getStandingBonuses();
		[[nodiscard]] FortBonuses& getFortBonuses();

	private:
		TradeSkills trade_skills;
		ArmourSets armour_sets;
		Taxes taxes;
		StandingBonuses standing_bonuses;
		FortBonuses fort_bonuses;
};
