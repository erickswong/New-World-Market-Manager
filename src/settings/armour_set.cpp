module settings:armour_set;

import exceptions;

namespace settings::armour_sets {
	void ArmourSet::reset() noexcept {
		has_hat    = false;
		has_shirt  = false;
		has_gloves = false;
		has_pants  = false;
		has_shoes  = false;
	}

	void ArmourSet::fromJson(const Json::Value& json_value, std::string armour_set) {
		try {
			has_hat    = json_value["has_hat"].asBool();
			has_shirt  = json_value["has_shirt"].asBool();
			has_gloves = json_value["has_gloves"].asBool();
			has_pants  = json_value["has_pants"].asBool();
			has_shoes  = json_value["has_shoes"].asBool();
		} catch (const std::exception& e) {
			throw BadJsonException(armour_set + " is malformed", e);
		}
	}

	Json::Value ArmourSet::toJson() const {
		Json::Value json_value;

		json_value["has_hat"]    = Json::Value(has_hat);
		json_value["has_shirt"]  = Json::Value(has_shirt);
		json_value["has_gloves"] = Json::Value(has_gloves);
		json_value["has_pants"]  = Json::Value(has_pants);
		json_value["has_shoes"]  = Json::Value(has_shoes);

		return json_value;
	}

	int ArmourSet::numberAcquired() const {
		return has_hat + has_shirt + has_gloves + has_pants + has_shoes;
	}

	bool ArmourSet::getHasHat() const {
		return has_hat;
	}

	void ArmourSet::setHasHat(const bool new_has_helmet) {
		has_hat = new_has_helmet;
	}

	bool ArmourSet::getHasShirt() const {
		return has_shirt;
	}

	void ArmourSet::setHasShirt(const bool new_has_chest) {
		has_shirt = new_has_chest;
	}

	bool ArmourSet::getHasGloves() const {
		return has_gloves;
	}

	void ArmourSet::setHasGloves(const bool new_has_gloves) {
		has_gloves = new_has_gloves;
	}

	bool ArmourSet::getHasPants() const {
		return has_pants;
	}

	void ArmourSet::setHasPants(const bool new_has_pants) {
		has_pants = new_has_pants;
	}

	bool ArmourSet::getHasShoes() const {
		return has_shoes;
	}

	void ArmourSet::setHasShoes(const bool new_has_shoes) {
		has_shoes = new_has_shoes;
	}
}
