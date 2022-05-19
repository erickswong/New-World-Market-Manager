#include "settings/armour_set.h"

ArmourSet::ArmourSet() = default;

ArmourSet::ArmourSet(const bool has_helmet,
					 const bool has_chest,
					 const bool has_gloves,
					 const bool has_pants,
					 const bool has_shoes)
						 : has_hat(has_helmet),
                           has_shirt(has_chest),
                           has_gloves(has_gloves),
                           has_pants(has_pants),
                           has_shoes(has_shoes) {
}

ArmourSet::ArmourSet(Json::Value json_value)
	: has_hat(json_value["has_hat"].asBool()),
	  has_shirt(json_value["has_shirt"].asBool()),
	  has_gloves(json_value["has_gloves"].asBool()),
	  has_pants(json_value["has_pants"].asBool()),
  	  has_shoes(json_value["has_shoes"].asBool()) {
}

Json::Value ArmourSet::getJsonValue() const {
	Json::Value json_value;

	json_value["has_hat"] = Json::Value(has_hat);
	json_value["has_shirt"] = Json::Value(has_shirt);
	json_value["has_gloves"] = Json::Value(has_gloves);
	json_value["has_pants"] = Json::Value(has_pants);
	json_value["has_shoes"] = Json::Value(has_shoes);

	return json_value;
}

int ArmourSet::numberAcquired() const {
	return has_hat + has_shirt + has_gloves + has_pants + has_shoes;
}

bool ArmourSet::getHasHat() const {
	return has_hat;
}

void ArmourSet::setHasHat(const bool has_helmet) {
	this->has_hat = has_helmet;
}

bool ArmourSet::getHasShirt() const {
	return has_shirt;
}

void ArmourSet::setHasShirt(const bool has_chest) {
	this->has_shirt = has_chest;
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
