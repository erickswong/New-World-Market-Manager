#pragma once

class TradeSkills {
	public:
		TradeSkills();
		TradeSkills(int smelting_level,
			   int woodworking_level,
			   int leatherworking_level,
			   int weaving_level,
			   int stonecutting_level);

		[[nodiscard]] double smeltingYieldBonus() const;
		[[nodiscard]] double woodworkingYieldBonus() const;
		[[nodiscard]] double leatherworkingYieldBonus() const;
		[[nodiscard]] double weavingYieldBonus() const;
		[[nodiscard]] double stonecuttingYieldBonus() const;

		[[nodiscard]] int getSmeltingLevel() const;
		void setSmeltingLevel(int smelting_level);

		[[nodiscard]] int getWoodworkingLevel() const;
		void setWoodworkingLevel(int woodworking_level);

		[[nodiscard]] int getLeatherworkingLevel() const;
		void setLeatherworkingLevel(int leatherworking_level);

		[[nodiscard]] int getWeavingLevel() const;
		void setWeavingLevel(int weaving_level);

		[[nodiscard]] int getStonecuttingLevel() const;
		void setStonecuttingLevel(int stonecutting_level);

	private:
		int smelting_level = 200;
		int woodworking_level = 200;
		int leatherworking_level = 200;
		int weaving_level = 200;
		int stonecutting_level = 200;
};
