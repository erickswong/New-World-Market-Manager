#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_marketmanager.h"

class MarketManager : public QMainWindow
{
    Q_OBJECT

public:
    MarketManager(QWidget *parent = Q_NULLPTR);

private:
    Ui::MarketManagerClass ui;
};
