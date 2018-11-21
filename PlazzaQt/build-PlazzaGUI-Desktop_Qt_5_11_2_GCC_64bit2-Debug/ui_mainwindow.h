/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QPushButton *runButton;
    QListView *cookingListView;
    QLineEdit *filePathLineEdit;
    QPushButton *browseButton;
    QPushButton *setTimeButton;
    QLineEdit *timeLineEdit;
    QPushButton *kitchenButton;
    QLineEdit *kitchenLineEdit;
    QPushButton *cookButton;
    QLineEdit *cookerLineEdit;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(638, 577);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(220, 180, 301, 25));
        runButton = new QPushButton(centralWidget);
        runButton->setObjectName(QStringLiteral("runButton"));
        runButton->setGeometry(QRect(20, 180, 89, 25));
        cookingListView = new QListView(centralWidget);
        cookingListView->setObjectName(QStringLiteral("cookingListView"));
        cookingListView->setGeometry(QRect(20, 230, 601, 301));
        filePathLineEdit = new QLineEdit(centralWidget);
        filePathLineEdit->setObjectName(QStringLiteral("filePathLineEdit"));
        filePathLineEdit->setGeometry(QRect(220, 10, 401, 25));
        browseButton = new QPushButton(centralWidget);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        browseButton->setGeometry(QRect(20, 10, 111, 25));
        setTimeButton = new QPushButton(centralWidget);
        setTimeButton->setObjectName(QStringLiteral("setTimeButton"));
        setTimeButton->setGeometry(QRect(20, 50, 89, 25));
        timeLineEdit = new QLineEdit(centralWidget);
        timeLineEdit->setObjectName(QStringLiteral("timeLineEdit"));
        timeLineEdit->setGeometry(QRect(220, 50, 401, 25));
        kitchenButton = new QPushButton(centralWidget);
        kitchenButton->setObjectName(QStringLiteral("kitchenButton"));
        kitchenButton->setGeometry(QRect(20, 90, 171, 25));
        kitchenLineEdit = new QLineEdit(centralWidget);
        kitchenLineEdit->setObjectName(QStringLiteral("kitchenLineEdit"));
        kitchenLineEdit->setGeometry(QRect(220, 90, 401, 25));
        cookButton = new QPushButton(centralWidget);
        cookButton->setObjectName(QStringLiteral("cookButton"));
        cookButton->setGeometry(QRect(20, 130, 171, 25));
        cookerLineEdit = new QLineEdit(centralWidget);
        cookerLineEdit->setObjectName(QStringLiteral("cookerLineEdit"));
        cookerLineEdit->setGeometry(QRect(220, 130, 401, 25));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 638, 22));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        runButton->setText(QApplication::translate("MainWindow", "Run", nullptr));
        browseButton->setText(QApplication::translate("MainWindow", "Browse Button", nullptr));
        setTimeButton->setText(QApplication::translate("MainWindow", "Set Time", nullptr));
        kitchenButton->setText(QApplication::translate("MainWindow", "Set Number Of Kitchens ", nullptr));
        cookButton->setText(QApplication::translate("MainWindow", "Set Number Of Cookers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
