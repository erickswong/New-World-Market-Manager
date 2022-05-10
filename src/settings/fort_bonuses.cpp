#include "settings/fort_bonuses.h"

#include "constants.h"

FortBonuses::FortBonuses() = default;

FortBonuses::FortBonuses(const bool has_first_light,
						 const bool has_weavers_fen)
							 : has_first_light(has_first_light),
                               has_weavers_fen(has_weavers_fen) {
}

double FortBonuses::yieldBonus() const {
	return FIRST_LIGHT_YIELD_BONUS * has_first_light;
}

double FortBonuses::taxBonus() const {
	return WEAVERS_FEN_TAX_BONUS * has_weavers_fen;
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
