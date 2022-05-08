#include "settings/armour_set.h"

ArmourSet::ArmourSet() = default;

ArmourSet::ArmourSet(const bool has_helmet,
					 const bool has_chest,
					 const bool has_gloves,
					 const bool has_pants,
					 const bool has_shoes)
						 : has_helmet(has_helmet),
                           has_chest(has_chest),
                           has_gloves(has_gloves),
                           has_pants(has_pants),
                           has_shoes(has_shoes) {
}

double ArmourSet::totalBonus() const {
	return (has_helmet + has_chest + has_gloves + has_pants + has_shoes) * bonus_per_piece;
}

bool ArmourSet::getHasHelmet() const {
	return has_helmet;
}

void ArmourSet::setHasHelmet(const bool has_helmet) {
	this->has_helmet = has_helmet;
}

bool ArmourSet::getHasChest() const {
	return has_chest;
}

void ArmourSet::setHasChest(const bool has_chest) {
	this->has_chest = has_chest;
}

bool ArmourSet::getHasGloves() const {
	return has_gloves;
}

void ArmourSet::setHasGloves(const bool has_gloves) {
	this->has_gloves = has_gloves;
}

bool ArmourSet::getHasPants() const {
	return has_pants;
}

void ArmourSet::setHasPants(const bool has_pants) {
	this->has_pants = has_pants;
}

bool ArmourSet::getHasShoes() const {
	return has_shoes;
}

void ArmourSet::setHasShoes(const bool has_shoes) {
	this->has_shoes = has_shoes;
}
