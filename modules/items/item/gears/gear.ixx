export module items:gear;

import :item;

namespace items {
	export class Gear : public Item {
		bool acquired;

		protected:
			Gear(const std::string& item_name,
			     bool acquired);
			explicit Gear(const Json::Value& json_value);

		public:
			virtual ~Gear() = default;

			// Returns a json representing this object
			[[nodiscard]] Json::Value toJson() const override;

			// Returns acquired
			[[nodiscard]] bool getAcquired() const;
			// Sets acquired
			void setAcquired(bool acquired);
	};
}