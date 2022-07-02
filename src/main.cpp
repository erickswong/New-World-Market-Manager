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
        // exceptions::writeToDisk(BadJsonException("sss").what()); // TODO: find out why custom exceptions don't work only in main
        exceptions::writeToDisk(e.what());                          //       remove .what() workaround after above fixed
    }
}
