export module items:resource;

import :item;

namespace items {
	export class Resource : public Item {
		protected:
			Resource(const std::string& item_name,
					 const std::string& image_path,
					 int tier,
					 bool buy_equals_sell,
					 double sell_price,
					 double buy_price);
			explicit Resource(Json::Value json_value);
			
		public:
			/**
			 * @brief Returns a json representing this object
			 * 
			 * @return The json
			 */
			[[nodiscard]] Json::Value toJson() const override;

			int getTier() override;

			bool getBuyEqualsSell() override;

			/**
			 * @brief Set the state of buy equals sell
			 * 
			 * @param buy_equals_sell 
			 * @return Whether there is a change in the sell or buy price
			 */
			bool setBuyEqualsSell(bool buy_equals_sell) override;

			double getSellPrice() override;

			/**
			 * @brief Set the sell price
			 * 
			 * @param sell_price 
			 * @return Whether there is a change in the sell or buy price
			 */
			bool setSellPrice(double sell_price) override;

			double getBuyPrice() override;
			
			/**
			 * @brief Set the buy price
			 * 
			 * @param buy_price 
			 * @return Whether there is a change in the sell or buy price
			 */
			bool setBuyPrice(double buy_price) override;

			std::list<Item*> getItemUpdateOrder() override;

			void setItemUpdateOrder(std::list<Item*> item_update_order) override;

			double getBestInstantAcquireCost() override;

			double getBestAcquireCost() override;
	};
};
