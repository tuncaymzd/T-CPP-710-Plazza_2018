#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <string>
#include "include/Controleur.hpp"
#include "shared/includes/Delegates.h"
#include "include/Dispatcher.h"

using std::string;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void browseButtonClicked();
    void setTimeClicked();
    void setCookerClicked();
    void setKitchenClicked();
    void runClicked();
    void populateListView(string message);
    void runProcesses();
    void setNotif(notifierEventHandler n){
        notif = n;
    }

private:
    Ui::MainWindow *ui;
    Controleur *c;
    QStringListModel *model;
    int timeCount = 0;
    int cookerCount = 0;
    int kitchenCount = 0;
    string configFile = "";
    notifierEventHandler notif;
};

#endif // MAINWINDOW_H
