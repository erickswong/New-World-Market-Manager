export module items:item;

import "json/json.h";
import :recipes;

namespace items {
	export class Item {
		std::string item_name;
		std::string image_path;
		std::list<Item*> item_update_order;
		
		protected:
			Item(const std::string& item_name,
				 const std::string& image_path);
			explicit Item(const Json::Value& json_value);

		public:
			virtual ~Item() = default;

			// Returns a json representing this object
			[[nodiscard]] virtual Json::Value toJson() const;

			// Returns item_name
			[[nodiscard]] std::string getItemName() const;
			
			// Returns image_path
			[[nodiscard]] std::string getImagePath() const;

			// Returns item_update_order
			[[nodiscard]] std::list<Item*> getItemUpdateOrder();
			// Sets item_update_order
			void setItemUpdateOrder(std::list<Item*> item_update_order);
	};
};
