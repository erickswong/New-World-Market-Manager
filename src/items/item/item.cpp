module items:item;

import exceptions;
import image_map;

namespace items {
	Item::Item(const std::string& item_name) :
		item_name(item_name) {
	}

	Item::Item(const Json::Value& json_value) :
		item_name(json_value["item_name"].asString()) {
	}

	Json::Value Item::toJson() const {
		Json::Value json_value;

		json_value["item_name"]  = item_name;

		// Uncomment to save item update order in json
		/*{
			Json::Value item_update_order_json_value;
			for (const auto& item : item_update_order) {
				item_update_order_json_value.append(item->getItemName());
			}
			json_value["item_update_order"] = item_update_order_json_value;
		}*/

		return json_value;
	}

	std::string Item::imagePath() const {
		return image_map::getPath(item_name);
	}

	std::string Item::getItemName() const {
		return item_name;
	}

	std::list<Item*> Item::getItemUpdateOrder() const {
		return item_update_order;
	}

	void Item::setItemUpdateOrder(std::list<Item*> item_update_order) {
		this->item_update_order = item_update_order;
	}
}
