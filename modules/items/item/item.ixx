export module items:item;

import "json/json.h";
import :recipes;

namespace items {
	export struct ItemAnalysis { // TODO: rename to CraftAnalysis
		double best_instant_craft_cost = HUGE_VAL;
		double best_craft_cost = HUGE_VAL;
		double best_instant_profit_margin = -HUGE_VAL;
		double best_profit_margin = -HUGE_VAL;
		Recipe best_instant_recipe;
		Recipe best_recipe;
	};

	export class Item {
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
			
			/**
			 * @brief Construct a new Item object
			 * 
			 * @param item_name 
			 * @param image_path 
			 */
			Item(const std::string& item_name,
				 const std::string& image_path); // TODO: look at using optional parameters

			/**
			 * @brief Construct a new Item object
			 * 
			 * @param json_value 
			 */
			explicit Item(Json::Value json_value);

		public:
			/**
			 * @brief Destroy the Item object
			 */
			virtual ~Item() = default;

			// TODO: turn into pure virtual function
			/**
			 * @brief Returns a json representing this object
			 * 
			 * @return The json
			 */
			[[nodiscard]] virtual Json::Value toJson() const;

			virtual std::string getItemName();

			// TODO: turn into pure virtual function
			virtual int getTier();

			virtual bool getBuyEqualsSell();

			/**
			 * @brief Set the state of buy equals sell
			 * 
			 * @param buy_equals_sell 
			 * @return Whether there is a change in the sell or buy price
			 */
			virtual bool setBuyEqualsSell(bool buy_equals_sell);

			virtual double getSellPrice();

			/**
			 * @brief Set the sell price
			 * 
			 * @param sell_price 
			 * @return Whether there is a change in the sell or buy price
			 */
			virtual bool setSellPrice(double sell_price);

			virtual double getBuyPrice();
			
			/**
			 * @brief Set the buy price
			 * 
			 * @param buy_price 
			 * @return Whether there is a change in the sell or buy price
			 */
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
	};
};
