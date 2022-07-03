export module items:item;

import "json/json.h";
import <list>;

namespace items {
	export class Item {
		std::string item_name;
		std::list<Item*> item_update_order;
		
		protected:
			explicit Item(const std::string& item_name);
			explicit Item(const Json::Value& json_value);

		public:
			virtual ~Item() = default;

			// Returns a json representing this object
			[[nodiscard]] virtual Json::Value toJson() const;
			
			// Returns image_path
			[[nodiscard]] std::string imagePath() const;

			// Returns item_name
			[[nodiscard]] std::string getItemName() const;

			// Returns item_update_order
			[[nodiscard]] std::list<Item*> getItemUpdateOrder() const;
			// Sets item_update_order
			void setItemUpdateOrder(std::list<Item*> item_update_order);
	};
};
