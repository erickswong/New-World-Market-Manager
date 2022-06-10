module settings:fort_bonuses;

FortBonuses::FortBonuses() = default;

FortBonuses::FortBonuses(const bool has_first_light,
						 const bool has_weavers_fen)
							 : has_first_light(has_first_light),
                               has_weavers_fen(has_weavers_fen) {
}

FortBonuses::FortBonuses(Json::Value json_value)
	: has_first_light(json_value["has_first_light"].asBool()),
	  has_weavers_fen(json_value["has_weavers_fen"].asBool()) {
}

Json::Value FortBonuses::toJson() const {
	Json::Value json_value;

	json_value["has_first_light"] = Json::Value(has_first_light);
	json_value["has_weavers_fen"] = Json::Value(has_weavers_fen);

	return json_value;
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
