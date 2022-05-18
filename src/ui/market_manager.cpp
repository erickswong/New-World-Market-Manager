#include "ui/market_manager.h"
#include "stdafx.h"

MarketManager::MarketManager(QWidget *parent)
    : QMainWindow(parent) {
    ui.setupUi(this);

    // Remove title bar
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint); // TODO: Qt::WindowStaysOnTopHint
    setAttribute(Qt::WA_TranslucentBackground);

    // Apply drop shadow effect
    setDropShadow();

    // Initialize items and settings
    setItems();
    setSettings();

    // Set stacked widget to default page
    ui.content_stacked_widget->setCurrentIndex(static_cast<int>(MenuButtons::SMELTING));
}

MarketManager::~MarketManager() {
    delete shadow;
    delete items;
    delete settings;
}

void MarketManager::mousePressEvent(QMouseEvent* event) {
	const QPointF mouse_global_pos = event->globalPosition();
	const QPointF mouse_pos = event->position();

    // Move or resize window
    if (widgetContainsPoint(ui.header_bar, mouse_global_pos) || widgetContainsPoint(ui.menu_header, mouse_global_pos)) {
    	// Restore down if maximized
        if (isMaximized()) {
            setNormal();
        }

        // Move window
        windowHandle()->startSystemMove();
    } else if (!widgetContainsPoint(ui.drop_shadow_frame, mouse_global_pos)) {
        // No resizing if maximized
        if (isMaximized()) {
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
        windowHandle()->startSystemResize(edges);
    }
}

void MarketManager::mouseDoubleClickEvent(QMouseEvent* event) {
	const QPointF mouse_global_pos = event->globalPosition();

    // Double clicking header has same effect as clicking maximize/restore button
	if (widgetContainsPoint(ui.header_bar, mouse_global_pos) || widgetContainsPoint(ui.menu_header, mouse_global_pos)) {
        on_maximize_restore_button_clicked();
    }
}

void MarketManager::on_menu_control_button_clicked(const bool checked) const {
	if (checked) {
        // Change to collapse menu tooltip
        ui.menu_control_button->setToolTip("Collapse Menu");

        // Restore text to buttons
        ui.smelting_button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui.woodworking_button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui.weaving_button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui.leatherworking_button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui.stonecutting_button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        ui.settings_button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
		// Change to expand menu tooltip
	} else {
        ui.menu_control_button->setToolTip("Expand Menu");

        // Remove text from buttons
        ui.smelting_button->setToolButtonStyle(Qt::ToolButtonIconOnly);
        ui.woodworking_button->setToolButtonStyle(Qt::ToolButtonIconOnly);
        ui.weaving_button->setToolButtonStyle(Qt::ToolButtonIconOnly);
        ui.leatherworking_button->setToolButtonStyle(Qt::ToolButtonIconOnly);
        ui.stonecutting_button->setToolButtonStyle(Qt::ToolButtonIconOnly);
        ui.settings_button->setToolButtonStyle(Qt::ToolButtonIconOnly);
	}
}

void MarketManager::on_smelting_button_clicked() const {
    ui.smelting_button->setChecked(true);
    menuButtonClicked(MenuButtons::SMELTING);
}

void MarketManager::on_woodworking_button_clicked() const {
    ui.woodworking_button->setChecked(true);
    menuButtonClicked(MenuButtons::WOODWORKING);
}

void MarketManager::on_weaving_button_clicked() const {
    ui.weaving_button->setChecked(true);
    menuButtonClicked(MenuButtons::WEAVING);
}

void MarketManager::on_leatherworking_button_clicked() const {
    ui.leatherworking_button->setChecked(true);
    menuButtonClicked(MenuButtons::LEATHERWORKING);
}

void MarketManager::on_stonecutting_button_clicked() const {
    ui.stonecutting_button->setChecked(true);
    menuButtonClicked(MenuButtons::STONECUTTING);
}

void MarketManager::on_settings_button_clicked() const {
    ui.settings_button->setChecked(true);
    menuButtonClicked(MenuButtons::SETTINGS);
}

void MarketManager::on_minimize_button_clicked() {
    showMinimized();
}

void MarketManager::on_maximize_restore_button_clicked() {
    if (isMaximized()) {
        // Restore Down
        setNormal();
        showNormal();
    } else {
        // Maximize
        setMaximized();
        showMaximized();
    }
}

void MarketManager::on_close_button_clicked() {
    close();
}

void MarketManager::menuButtonClicked(const MenuButtons button) const {
    // Uncheck every other button
    if (button != MenuButtons::SMELTING) {
        ui.smelting_button->setChecked(false);
    }
    if (button != MenuButtons::WOODWORKING) {
        ui.woodworking_button->setChecked(false);
    }
    if (button != MenuButtons::WEAVING) {
        ui.weaving_button->setChecked(false);
    }
    if (button != MenuButtons::LEATHERWORKING) {
        ui.leatherworking_button->setChecked(false);
    }
    if (button != MenuButtons::STONECUTTING) {
        ui.stonecutting_button->setChecked(false);
    }
    if (button != MenuButtons::SETTINGS) {
        ui.settings_button->setChecked(false);
    }

    // Set stacked widget to correct page
    ui.content_stacked_widget->setCurrentIndex(static_cast<int>(button));
}

void MarketManager::setDropShadow() {
    shadow = new QGraphicsDropShadowEffect;
    shadow->setBlurRadius(2 * BORDER_SIZE);
    shadow->setXOffset(0);
    shadow->setYOffset(0);
    shadow->setColor(QColor(0, 0, 0, 200));
    ui.drop_shadow_frame->setGraphicsEffect(shadow);
}

void MarketManager::setItems() {
    items = new Items;

    // TODO: have initializer

    // Set items for all children
    ui.smelting_page->setItems(items);
}

void MarketManager::setSettings() {
    settings = new Settings;

    // TODO: have initializer

    // Set settings for all children
    ui.smelting_page->setSettings(settings);
}

void MarketManager::setNormal() const {
    // Change to maximize button
    ui.maximize_restore_button->setChecked(false);
    ui.maximize_restore_button->setToolTip("Maximize");

    // Restore borders
    ui.border_top_left->setMinimumSize(BORDER_SIZE, BORDER_SIZE);
    ui.border_top_left->setMaximumSize(BORDER_SIZE, BORDER_SIZE);
    ui.border_bottom_right->setMinimumSize(BORDER_SIZE, BORDER_SIZE);
    ui.border_bottom_right->setMaximumSize(BORDER_SIZE, BORDER_SIZE);

    // Restore border-radius
    ui.drop_shadow_frame->setStyleSheet("#drop_shadow_frame {"
                                        "background-color: rgb(33, 43, 51);"
                                        "border-radius: 10px;"
                                        "}");
    ui.menu_header->setStyleSheet("#menu_header {"
                                  "background-color: rgb(61, 80, 95);"
                                  "border-top-left-radius: 10px;"
                                  "}");
    ui.header_bar->setStyleSheet("#header_bar {"
                                 "background-color: rgb(61, 80, 95);"
                                 "border-top-right-radius: 10px;"
                                 "}");
}

void MarketManager::setMaximized() const {
    // Change to restore button
    ui.maximize_restore_button->setChecked(true);
    ui.maximize_restore_button->setToolTip("Restore Down");

    // Remove borders
    ui.border_top_left->setMinimumSize(0, 0);
    ui.border_top_left->setMaximumSize(0, 0);
    ui.border_bottom_right->setMinimumSize(0, 0);
    ui.border_bottom_right->setMaximumSize(0, 0);

    // Remove border-radius
    ui.drop_shadow_frame->setStyleSheet("#drop_shadow_frame {"
                                        "background-color: rgb(33, 43, 51);"
                                        "border-radius: 0px;"
                                        "}");
    ui.menu_header->setStyleSheet("#menu_header {"
                                  "background-color: rgb(61, 80, 95);"
                                  "border-top-left-radius: 0px;"
                                  "}");
    ui.header_bar->setStyleSheet("#header_bar {"
                                 "background-color: rgb(61, 80, 95);"
                                 "border-top-right-radius: 0px;"
                                 "}");
}

bool MarketManager::widgetContainsPoint(const QWidget* widget, const QPointF global_pos) {
    return QRectF(widget->rect()).contains(widget->mapFromGlobal(global_pos));
}
