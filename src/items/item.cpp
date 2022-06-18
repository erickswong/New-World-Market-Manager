module items:item;

import exceptions;

Item::Item(std::string item_name,
           std::string image_path)
			   : item_name(std::move(item_name)),
                 image_path(std::move(image_path)) {
}

Item::Item(Json::Value json_value)
	: item_name(json_value["item_name"].asString()),
      image_path(json_value["image_path"].asString()) {
}

Item::~Item() = default;

Json::Value Item::toJson() const {
	Json::Value json_value;

	json_value["item_type"] = "Item";
	json_value["item_name"] = item_name;
	json_value["image_path"] = image_path;

	return json_value;
}

std::string Item::getItemName() {
	return item_name;
}

int Item::getTier() {
	throw NotUsedException("Item \"" + item_name + "\" does not use getTier");
}

bool Item::getBuyEqualsSell() {
	throw NotUsedException("Item \"" + item_name + "\" does not use getBuyEqualsSell");
}

bool Item::setBuyEqualsSell(const bool buy_equals_sell) {
	throw NotUsedException("Item \"" + item_name + "\" does not use setBuyEqualsSell");
}

double Item::getSellPrice() {
	throw NotUsedException("Item \"" + item_name + "\" does not use getSellPrice");
}

bool Item::setSellPrice(const double sell_price) {
	throw NotUsedException("Item \"" + item_name + "\" does not use setSellPrice");
}

double Item::getBuyPrice() {
	throw NotUsedException("Item \"" + item_name + "\" does not use getBuyPrice");
}

bool Item::setBuyPrice(const double buy_price) {
	throw NotUsedException("Item \"" + item_name + "\" does not use setBuyPrice");
}

double Item::getBaseYield() {
	throw NotUsedException("Item \"" + item_name + "\" does not use getBaseYield");
}

double Item::getBaseCraftTax() {
	throw NotUsedException("Item \"" + item_name + "\" does not use getBaseCraftTax");
}

Recipes& Item::getRecipes() {
	throw NotUsedException("Item \"" + item_name + "\" does not use getRecipes");
}

std::string Item::getImagePath() {
	return image_path;
}

std::list<Item*> Item::getItemUpdateOrder() {
	throw NotUsedException("Item \"" + item_name + "\" does not use getItemUpdateOrder");
}

void Item::setItemUpdateOrder(std::list<Item*> item_update_order) {
	throw NotUsedException("Item \"" + item_name + "\" does not use setItemUpdateOrder");
}

ItemAnalysis& Item::getAnalysis() {
	throw NotUsedException("Item \"" + item_name + "\" does not use getAnalysis");
}

double Item::getBestInstantAcquireCost() {
	throw NotUsedException("Item \"" + item_name + "\" does not use getBestInstantAcquireCost");
}

double Item::getBestAcquireCost() {
	throw NotUsedException("Item \"" + item_name + "\" does not use getBestAcquireCost");
}

double Item::getCraftTax() {
	throw NotUsedException("Item \"" + item_name + "\" does not use getCraftTax");
}

double Item::getYield(Recipe& recipe) {
	throw NotUsedException("Item \"" + item_name + "\" does not use getYield");
}
