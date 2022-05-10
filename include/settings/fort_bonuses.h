#pragma once

class FortBonuses {
	public:
		FortBonuses();
		FortBonuses(bool has_first_light,
					bool has_weavers_fen);

		[[nodiscard]] double yieldBonus() const;
		[[nodiscard]] double taxBonus() const;

		[[nodiscard]] bool getHasFirstLight() const;
		void setHasFirstLight(bool has_first_light);

		[[nodiscard]] bool getHasWeaversFen() const;
		void setHasWeaversFen(bool has_weavers_fen);

	private:
		bool has_first_light = false;
		bool has_weavers_fen = false;
};
