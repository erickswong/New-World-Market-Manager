export module items:refining_gear;

import :gear;

namespace items {
	export class RefiningGear final : public Gear {
		double yield_bonus;

		public:
			RefiningGear(const std::string& item_name,
						 bool acquired,
						 double yield_bonus);
			explicit RefiningGear(const Json::Value& json_value);

			// Returns a json representing this object
			[[nodiscard]] Json::Value toJson() const override;

			// Returns the applied yield bonus
			[[nodiscard]] double yieldBonus() const;
	};
};
