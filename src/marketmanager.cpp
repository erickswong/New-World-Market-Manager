#include "marketmanager.h"
#include "stdafx.h"

MarketManager::MarketManager(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // Remove title bar
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint); // Qt::WindowStaysOnTopHint
    this->setAttribute(Qt::WA_TranslucentBackground);

    // Apply drop shadow effect
    shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(20);
    shadow->setXOffset(0);
    shadow->setYOffset(0);
    shadow->setColor(QColor(0, 0, 0, 200));
    ui.drop_shadow_frame->setGraphicsEffect(shadow);
}

MarketManager::~MarketManager() {
    delete shadow;
}

void MarketManager::mousePressEvent(QMouseEvent* event) {
    Qt::Edges edges;
    constexpr qreal border = 20;
    QPoint mouse_pos = event->pos();

    // Determine the edges that the mouse is near
    if (mouse_pos.x() > width() - border) {
        edges |= Qt::RightEdge;
    }
    if (mouse_pos.x() < border) {
        edges |= Qt::LeftEdge;
    }
    if (mouse_pos.y() < border) {
        edges |= Qt::TopEdge;
    }
    if (mouse_pos.y() > height() - border) {
        edges |= Qt::BottomEdge;
    }

    // Resize or move window
    if (edges != 0) {
        // Resize window
        this->windowHandle()->startSystemResize(edges);
    } else if (ui.frame_title->geometry().contains(mouse_pos)) {
        if (this->isMaximized()) {
            // Change to maximize button
            ui.maximize_restore->setIcon(QIcon(":/MarketManager/images/title_bar/maximize.png"));
            ui.maximize_restore->setToolTip("Maximize");

            // Restore margins and border-radius
            ui.mainLayout->setContentsMargins(10, 10, 10, 10);
            ui.drop_shadow_frame->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(37, 37, 38, 255), stop:0.5 rgba(31, 31, 31, 255));"
                                                "border-radius: 10px;");

            // Restore border-top-right-radius to close button
            ui.close->setStyleSheet("QPushButton {"
                                    "   border: none;"
                                    "   background: transparent;"
                                    "}"
                                    "QPushButton:hover {"
                                    "background-color: red;"
                                    "border-radius: 0px;"
                                    "border-top-right-radius: 10px;"
                                    "}");
        }

        // Move window
        this->windowHandle()->startSystemMove();
    }
}

void MarketManager::mouseDoubleClickEvent(QMouseEvent* event) {
    QPoint mouse_pos = event->pos();

    if (ui.frame_title->geometry().contains(mouse_pos)) {
        on_maximize_restore_clicked();
    }
}

void MarketManager::on_minimize_clicked() {
    this->showMinimized();
}

void MarketManager::on_maximize_restore_clicked() {
    if (this->isMaximized()) {
        // Restore Down
        this->showNormal();

        // Change to maximize button
        ui.maximize_restore->setIcon(QIcon(":/MarketManager/images/title_bar/maximize.png"));
        ui.maximize_restore->setToolTip("Maximize");

        // Restore margins and border-radius
        ui.mainLayout->setContentsMargins(10, 10, 10, 10);
        ui.drop_shadow_frame->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(37, 37, 38, 255), stop:0.5 rgba(31, 31, 31, 255));"
                                     "border-radius: 10px;");

        // Restore border-top-right-radius to close button
        ui.close->setStyleSheet("QPushButton {"
                                "   border: none;"
                                "   background: transparent;"
                                "}"
                                "QPushButton:hover {"
                                "background-color: red;"
                                "border-radius: 0px;"
                                "border-top-right-radius: 10px;"
                                "}");
    } else {
        // Maximize
        this->showMaximized();

        // Change to restore button
        ui.maximize_restore->setIcon(QIcon(":/MarketManager/images/title_bar/restore_down.png"));
        ui.maximize_restore->setToolTip("Restore Down");

        // Remove margins and border-radius
        ui.mainLayout->setContentsMargins(0, 0, 0, 0);
        ui.drop_shadow_frame->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(37, 37, 38, 255), stop:0.5 rgba(31, 31, 31, 255));"
                                     "border-radius: 0px;");

        // Remove border-top-right-radius from close button
        ui.close->setStyleSheet("QPushButton {"
                                "   border: none;"
                                "   background: transparent;"
                                "}"
                                "QPushButton:hover {"
                                "background-color: red;"
                                "border-radius: 0px;"
                                "border-top-right-radius: 0px;"
                                "}");
    }
}

void MarketManager::on_close_clicked() {
    this->close();
}
