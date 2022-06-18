#pragma once

#include <QtWidgets/QMainWindow>
#include <QGraphicsDropShadowEffect>
#include "ui_market_manager.h"

class MarketManager final : public QMainWindow {
    Q_OBJECT

    public:
        static constexpr qreal BORDER_SIZE = 10;

		explicit MarketManager(QWidget *parent = Q_NULLPTR);
        ~MarketManager() override;

    protected:
        void mousePressEvent(QMouseEvent* event) override;
        void mouseDoubleClickEvent(QMouseEvent* event) override;

    private slots:
        void on_menu_control_button_clicked(bool checked) const;
        void on_smelting_button_clicked() const;
        void on_woodworking_button_clicked() const;
        void on_weaving_button_clicked() const;
        void on_leatherworking_button_clicked() const;
        void on_stonecutting_button_clicked() const;
        void on_settings_button_clicked() const;

        void on_minimize_button_clicked();
        void on_maximize_restore_button_clicked();
        void on_close_button_clicked();

    private:
        Ui::MarketManagerClass ui;
        QGraphicsDropShadowEffect* shadow;

        enum class MenuButtons {
            SMELTING,
            WOODWORKING,
            WEAVING,
            LEATHERWORKING,
            STONECUTTING,
            SETTINGS
        };

        void menuButtonClicked(MenuButtons button) const;

        void setDropShadow();
        void setNormal() const;
        void setMaximized() const;

        static bool widgetContainsPoint(const QWidget* widget, QPointF global_pos);
};
