export module settings:armour_set;

import "json/json.h";
import <string>;

namespace settings::armour_sets {
	export class ArmourSet {
		bool has_hat = false;
		bool has_shirt = false;
		bool has_gloves = false;
		bool has_pants = false;
		bool has_shoes = false;

		public:
			// Resets members to default values
			void reset() noexcept;

			// Sets members to values from json
			void fromJson(Json::Value json_value, std::string armour_set = "armour_set");
			// Returns a json representing this object
			[[nodiscard]] Json::Value toJson() const;

			// Returns the number of piece acquired in this armour set
			[[nodiscard]] int numberAcquired() const;

			[[nodiscard]] bool getHasHat() const;
			void setHasHat(bool new_has_helmet);

			[[nodiscard]] bool getHasShirt() const;
			void setHasShirt(bool new_has_chest);

			[[nodiscard]] bool getHasGloves() const;
			void setHasGloves(bool new_has_gloves);

			[[nodiscard]] bool getHasPants() const;
			void setHasPants(bool new_has_pants);

			[[nodiscard]] bool getHasShoes() const;
			void setHasShoes(bool new_has_shoes);
	};
};
