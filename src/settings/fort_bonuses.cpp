#include "settings/fort_bonuses.h"

FortBonuses::FortBonuses() = default;

FortBonuses::FortBonuses(const bool has_first_light,
						 const bool has_weavers_fen)
							 : has_first_light(has_first_light),
                               has_weavers_fen(has_weavers_fen) {
}

double FortBonuses::yieldBonus() const {
	return has_first_light * FIRST_LIGHT_BONUS;
}

double FortBonuses::taxBonus() const {
	return has_weavers_fen * WEAVERS_FEN_BONUS;
}

bool FortBonuses::getHasFirstLight() const {
	return has_first_light;
}

void FortBonuses::setHasFirstLight(const bool has_first_light) {
	this->has_first_light = has_first_light;
}

bool FortBonuses::getHasWeaversFen() const {
	return  has_weavers_fen;
}

void FortBonuses::setHasWeaversFen(const bool has_weavers_fen) {
	this->has_weavers_fen = has_weavers_fen;
}
