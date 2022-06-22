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
					 const std::string& image_path,
					 int tier,
					 bool buy_equals_sell,
					 double sell_price,
					 double buy_price);
			explicit Resource(Json::Value json_value);
			
		public:
			virtual ~Resource() = default;
			
			// Returns a json representing this object
			[[nodiscard]] Json::Value toJson() const override;

			// Returns the best instant acquire cost
			[[nodiscard]] virtual double bestInstantAcquireCost();

			// Returns the best acquire cost
			[[nodiscard]] virtual double bestAcquireCost();

			// Returns tier
			[[nodiscard]] int getTier();

			// Returns buy_equals_sell
			[[nodiscard]] bool getBuyEqualsSell();
			// Sets buy_equals_sell and returns whether there is a change in sell_price or buy_price
			bool setBuyEqualsSell(bool buy_equals_sell);

			// Returns sell_price
			[[nodiscard]] double getSellPrice();
			// Sets sell_price and returns whether there is a change in sell_price or buy_price
			bool setSellPrice(double sell_price);

			// Returns buy_price
			[[nodiscard]] double getBuyPrice();
			// Sets buy_price and returns whether there is a change in sell_price or buy_price
			bool setBuyPrice(double buy_price);
	};
};
