#pragma once

#include <QWidget>
#include "ui_flux_input_page.h"

#include "items/items.h"

class FluxInputPage final : public QWidget
{
	Q_OBJECT

	public:
		explicit FluxInputPage(QWidget *parent = Q_NULLPTR);

		void setItems(Items* items);
		void setSettings(Settings* settings);

	private:
		Ui::FluxInputPage ui;
		Items* items = nullptr;
		Settings* settings = nullptr;
};
