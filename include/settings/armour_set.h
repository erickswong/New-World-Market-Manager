#pragma once

class ArmourSet {
	public:
		ArmourSet();
		ArmourSet(bool has_helmet,
				  bool has_chest,
				  bool has_gloves,
				  bool has_pants,
				  bool has_shoes);

		[[nodiscard]] double yieldBonus() const;

		[[nodiscard]] bool getHasHelmet() const;
		void setHasHelmet(bool has_helmet);

		[[nodiscard]] bool getHasChest() const;
		void setHasChest(bool has_chest);

		[[nodiscard]] bool getHasGloves() const;
		void setHasGloves(bool has_gloves);

		[[nodiscard]] bool getHasPants() const;
		void setHasPants(bool has_pants);

		[[nodiscard]] bool getHasShoes() const;
		void setHasShoes(bool has_shoes);

	private:
		bool has_helmet = false;
		bool has_chest = false;
		bool has_gloves = false;
		bool has_pants = false;
		bool has_shoes = false;
};
