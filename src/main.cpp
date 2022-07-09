#include "ui/market_manager.h"
#include "stdafx.h"
#include <QtWidgets/QApplication>

import exceptions;

int main(int argc, char *argv[]) {
    try {
        // Create application
        QApplication a(argc, argv);

        // TODO: add SplashScreen on loading

        // Show Market Manager
        MarketManager w;
        w.show();

        // Throw return code if non-zero
        if (int returnCode = a.exec(); returnCode) {
            throw returnCode;
        }
    } catch (const std::exception& e) {
        exceptions::logCrash(e);
    } catch (int returnCode) {
        exceptions::logCrash(returnCode);
    }
}
