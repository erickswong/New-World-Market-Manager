#pragma once

#include <QWidget>

class InputItem : public QWidget {
	Q_OBJECT

	protected:
		InputItem(QWidget *parent);

	public:
		virtual ~InputItem() = default;
};
