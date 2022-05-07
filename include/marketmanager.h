#pragma once

#include <QtWidgets/QMainWindow>
#include <QGraphicsDropShadowEffect>
#include "ui_marketmanager.h"

class MarketManager : public QMainWindow {
    Q_OBJECT

    public:
        static constexpr qreal BORDER_SIZE = 10;

        MarketManager(QWidget *parent = Q_NULLPTR);
        ~MarketManager();

    protected:
        void mousePressEvent(QMouseEvent* event);
        void mouseDoubleClickEvent(QMouseEvent* event);

    private slots:
        void on_minimize_clicked();
        void on_maximize_restore_clicked();
        void on_close_clicked();

    private:
        Ui::MarketManagerClass ui;
        QGraphicsDropShadowEffect* shadow;

        void setDropShadow();
        void setBorderCursors();
        void setNormal();
        void setMaximized();
};
