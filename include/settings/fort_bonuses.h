#pragma once

class FortBonuses {
	public:
		static constexpr double FIRST_LIGHT_BONUS = 0.1;
		static constexpr double WEAVERS_FEN_BONUS = 0.1;

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
