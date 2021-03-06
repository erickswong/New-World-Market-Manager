export module items:resource;

import :item;

namespace items {
	export class Resource : public Item {
		int tier;
		bool buy_equals_sell;
		double sell_price;
		double buy_price;

		protected:
			Resource(const std::string& item_name,
					 int tier,
					 bool buy_equals_sell,
					 double sell_price,
					 double buy_price);
			explicit Resource(const Json::Value& json_value);
			
		public:
			virtual ~Resource() = default;
			
			// Returns a json representing this object
			[[nodiscard]] Json::Value toJson() const override;

			// Returns the best instant acquire cost
			[[nodiscard]] virtual double bestInstantAcquireCost() const;

			// Returns the best acquire cost
			[[nodiscard]] virtual double bestAcquireCost() const;

			// Returns tier
			[[nodiscard]] int getTier() const;

			// Returns buy_equals_sell
			[[nodiscard]] bool getBuyEqualsSell() const;
			// Sets buy_equals_sell and returns whether there is a change in sell_price or buy_price
			bool setBuyEqualsSell(bool buy_equals_sell);

			// Returns sell_price
			[[nodiscard]] double getSellPrice() const;
			// Sets sell_price and returns whether there is a change in sell_price or buy_price
			bool setSellPrice(double sell_price);

			// Returns buy_price
			[[nodiscard]] double getBuyPrice() const;
			// Sets buy_price and returns whether there is a change in sell_price or buy_price
			bool setBuyPrice(double buy_price);
	};
};
