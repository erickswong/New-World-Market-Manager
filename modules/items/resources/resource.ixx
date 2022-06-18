export module items:resource;

import :item;

namespace items {
	export class Resource : public Item {
		public:
			Resource(std::string item_name,
					 std::string image_path,
					 int tier,
					 bool buy_equals_sell,
					 double sell_price,
					 double buy_price);
			explicit Resource(Json::Value json_value);

			[[nodiscard]] Json::Value toJson() const override;

			int getTier() override;

			bool getBuyEqualsSell() override;
			// Sets the state of buy equals sell and returns true if there is a change in price
			bool setBuyEqualsSell(bool buy_equals_sell) override;

			double getSellPrice() override;
			// Sets the sell price and returns true if there is a change in price
			bool setSellPrice(double sell_price) override;

			double getBuyPrice() override;
			// Sets the buy price and returns true if there is a change in price
			bool setBuyPrice(double buy_price) override;

			std::list<Item*> getItemUpdateOrder() override;
			void setItemUpdateOrder(std::list<Item*> item_update_order) override;

			double getBestInstantAcquireCost() override;

			double getBestAcquireCost() override;
	};
};
