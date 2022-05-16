#pragma once

#include <QWidget>
#include "ui_ingot_input_page.h"

#include "items/items.h"

class IngotInputPage final : public QWidget
{
	Q_OBJECT

	public:
		explicit IngotInputPage(QWidget *parent = Q_NULLPTR);

		void setItems(Items* items);
		void setSettings(Settings* settings);

	private:
		Ui::IngotInputPage ui;
		Items* items = nullptr;
		Settings* settings = nullptr;
};
