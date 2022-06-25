module items:item;

import exceptions;

namespace items {
	Item::Item(const std::string& item_name,
			   const std::string& image_path) :
		item_name(item_name),
		image_path(image_path) {
	}

	Item::Item(const Json::Value& json_value) :
		item_name(json_value["item_name"].asString()),
		image_path(json_value["image_path"].asString()) {
	}

	Json::Value Item::toJson() const {
		Json::Value json_value;

		json_value["item_name"]  = item_name;
		json_value["image_path"] = image_path;

		// Uncomment to save item update order in json
		{
			Json::Value item_update_order_json_value;
			for (const auto& item : item_update_order) {
				item_update_order_json_value.append(item->getItemName());
			}
			json_value["item_update_order"] = item_update_order_json_value;
		}

		return json_value;
	}

	std::string Item::getItemName() const {
		return item_name;
	}

	std::string Item::getImagePath() const {
		return image_path;
	}

	std::list<Item*> Item::getItemUpdateOrder() const {
		return item_update_order;
	}

	void Item::setItemUpdateOrder(std::list<Item*> item_update_order) {
		this->item_update_order = item_update_order;
	}
}
