#include "ui/market_manager.h"
#include "stdafx.h"
#include <QtWidgets/QApplication>

import exceptions;

int main(int argc, char *argv[]) {
    try {
        // TODO: add SplashScreen on loading
        QApplication a(argc, argv);
        MarketManager w;
        w.show();
        return a.exec();
    } catch (const std::exception& e) {
        // exceptions::logCrash(new std::exception()); // TODO: find out why exceptions don't work only in main
        throw e;                                       //       rethrow e until above fixed
    }
}
