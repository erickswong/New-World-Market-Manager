#pragma once

#include "jsoncpp/json/json.h"

class ArmourSet {
	public:
		ArmourSet();
		ArmourSet(bool has_helmet,
				  bool has_chest,
				  bool has_gloves,
				  bool has_pants,
				  bool has_shoes);
		explicit ArmourSet(Json::Value json_value);

		[[nodiscard]] Json::Value toJson() const;

		[[nodiscard]] int numberAcquired() const;

		[[nodiscard]] bool getHasHat() const;
		void setHasHat(bool has_helmet);

		[[nodiscard]] bool getHasShirt() const;
		void setHasShirt(bool has_chest);

		[[nodiscard]] bool getHasGloves() const;
		void setHasGloves(bool has_gloves);

		[[nodiscard]] bool getHasPants() const;
		void setHasPants(bool has_pants);

		[[nodiscard]] bool getHasShoes() const;
		void setHasShoes(bool has_shoes);

	private:
		bool has_hat = false;
		bool has_shirt = false;
		bool has_gloves = false;
		bool has_pants = false;
		bool has_shoes = false;
};
