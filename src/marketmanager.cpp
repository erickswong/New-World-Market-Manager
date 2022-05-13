#include "marketmanager.h"
#include "stdafx.h"

MarketManager::MarketManager(QWidget *parent)
    : QMainWindow(parent) {
    ui.setupUi(this);

    // Remove title bar
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint); // TODO: Qt::WindowStaysOnTopHint
    this->setAttribute(Qt::WA_TranslucentBackground);

    // Apply drop shadow effect
    setDropShadow();
}

MarketManager::~MarketManager() {
    delete shadow;
}

void MarketManager::mousePressEvent(QMouseEvent* event) {
	const QPointF mouse_global_pos = event->globalPosition();
	const QPointF mouse_pos = event->position();

    // Move or resize window
    if (QRectF(ui.widget_title->rect()).contains(ui.widget_title->mapFromGlobal(mouse_global_pos))) {
        if (this->isMaximized()) {
            setNormal();
        }

        // Move window
        this->windowHandle()->startSystemMove();
    } else if (!QRectF(ui.drop_shadow_frame->rect()).contains(ui.drop_shadow_frame->mapFromGlobal(mouse_global_pos))) {
        // No resizing if maximized
        if (this->isMaximized()) {
            return;
        }

        Qt::Edges edges;

        // Determine the edges that the mouse is near
        if (mouse_pos.x() >= width() - 2 * BORDER_SIZE) {
            edges |= Qt::RightEdge;
        }
        if (mouse_pos.x() <= 2 * BORDER_SIZE) {
            edges |= Qt::LeftEdge;
        }
        if (mouse_pos.y() <= 2 * BORDER_SIZE) {
            edges |= Qt::TopEdge;
        }
        if (mouse_pos.y() >= height() - 2 * BORDER_SIZE) {
            edges |= Qt::BottomEdge;
        }

        // Resize window
        this->windowHandle()->startSystemResize(edges);
    }
}

void MarketManager::mouseDoubleClickEvent(QMouseEvent* event) {
	const QPointF mouse_global_pos = event->globalPosition();

	if (QRectF(ui.widget_title->rect()).contains(ui.widget_title->mapFromGlobal(mouse_global_pos))) {
        on_maximize_restore_clicked();
    }
}

void MarketManager::on_minimize_clicked() {
    this->showMinimized();
}

void MarketManager::on_maximize_restore_clicked() {
    if (this->isMaximized()) {
        // Restore Down
        setNormal();
        this->showNormal();
    } else {
        // Maximize
        setMaximized();
        this->showMaximized();
    }
}

void MarketManager::on_close_clicked() {
    this->close();
}

void MarketManager::setDropShadow() {
    shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(2 * BORDER_SIZE);
    shadow->setXOffset(0);
    shadow->setYOffset(0);
    shadow->setColor(QColor(0, 0, 0, 200));
    ui.drop_shadow_frame->setGraphicsEffect(shadow);
}

void MarketManager::setNormal() const {
    // Change to maximize button
    ui.maximize_restore->setIcon(QIcon(":/MarketManager/images/title_bar/maximize.png"));
    ui.maximize_restore->setToolTip("Maximize");

    // Restore borders
    ui.border_top_left->setMinimumSize(BORDER_SIZE, BORDER_SIZE);
    ui.border_top_left->setMaximumSize(BORDER_SIZE, BORDER_SIZE);
    ui.border_bottom_right->setMinimumSize(BORDER_SIZE, BORDER_SIZE);
    ui.border_bottom_right->setMaximumSize(BORDER_SIZE, BORDER_SIZE);

    // Restore border-radius
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

void MarketManager::setMaximized() const {
    // Change to restore button
    ui.maximize_restore->setIcon(QIcon(":/MarketManager/images/title_bar/restore_down.png"));
    ui.maximize_restore->setToolTip("Restore Down");

    // Remove borders
    ui.border_top_left->setMinimumSize(0, 0);
    ui.border_top_left->setMaximumSize(0, 0);
    ui.border_bottom_right->setMinimumSize(0, 0);
    ui.border_bottom_right->setMaximumSize(0, 0);

    // Remove border-radius
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
