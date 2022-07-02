#pragma once

#include <QWidget>

class InputItem : public QWidget {
	Q_OBJECT

	// A cyclic list is used here so that changing one InputItem will change all that have the same name.
	inline static std::unordered_map<std::string, InputItem*> input_item_map; // Stores a map from input_item_name to an InputItem to be considered the first in the cyclic list

	std::string name; // The name of this InputItem
	InputItem* prev;  // The previous InputItem in the cyclic list
	InputItem* next;  // The next InputItem in the cyclic list

	protected:
		InputItem(const std::string& name, QWidget *parent);

	public:
		virtual ~InputItem();

		// Returns the previous InputItem in the cyclic list
		template<typename T>
		[[nodiscard]] T* getPrev() const;

		// Returns the next InputItem in the cyclic list
		template<typename T>
		[[nodiscard]] T* getNext() const;

	private:
		// Inserts this into the cyclic list
		void insertIntoCyclicList();
		// Removes this from the cyclic list
		void removeFromCyclicList();
};

template<typename T>
inline T* InputItem::getPrev() const {
	return dynamic_cast<T*>(prev);
}

template<typename T>
inline T* InputItem::getNext() const {
	return dynamic_cast<T*>(next);
}
