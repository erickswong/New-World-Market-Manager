export module items:item;

import "json/json.h";
import :recipes;

namespace items {
	export struct ItemAnalysis {
		double best_instant_craft_cost = HUGE_VAL;
		double best_craft_cost = HUGE_VAL;
		double best_instant_profit_margin = -HUGE_VAL;
		double best_profit_margin = -HUGE_VAL;
		Recipe best_instant_recipe;
		Recipe best_recipe;
	};

	export class Item {
		public:
			Item(std::string item_name,
				 std::string image_path);
			explicit Item(Json::Value json_value);
			virtual ~Item();

			[[nodiscard]] virtual Json::Value toJson() const;

			virtual std::string getItemName();

			virtual int getTier();

			virtual bool getBuyEqualsSell();
			// Sets the state of buy equals sell and returns true if there is a change in price
			virtual bool setBuyEqualsSell(bool buy_equals_sell);

			virtual double getSellPrice();
			// Sets the sell price and returns true if there is a change in price
			virtual bool setSellPrice(double sell_price);

			virtual double getBuyPrice();
			// Sets the buy price and returns true if there is a change in price
			virtual bool setBuyPrice(double buy_price);

			virtual double getBaseYield();

			virtual double getBaseCraftTax();

			virtual Recipes& getRecipes();

			virtual std::string getImagePath();

			virtual std::list<Item*> getItemUpdateOrder();
			virtual void setItemUpdateOrder(std::list<Item*> item_update_order);

			virtual ItemAnalysis& getAnalysis();

			virtual double getBestInstantAcquireCost();

			virtual double getBestAcquireCost();

			virtual double getCraftTax();

			virtual double getYield(Recipe& recipe);

		protected:
			std::string item_name;
			int tier = 0;
			bool buy_equals_sell = true;
			double sell_price = HUGE_VAL;
			double buy_price = HUGE_VAL;
			double base_yield = 0.;
			double base_craft_tax = 0.;
			Recipes recipes;
			std::string image_path;
			std::list<Item*> item_update_order;

			ItemAnalysis analysis;
	};
};
