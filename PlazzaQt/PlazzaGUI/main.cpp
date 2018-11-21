#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <mutex>

std::mutex logMutex;

/// Log messages from underlying layers to the user.
/// \param text system logs.
void logNotification(string text) {
    logMutex.lock();
    std::cout << text << "\n";
    logMutex.unlock();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setNotif(logNotification);
    w.show();

    return a.exec();
}
