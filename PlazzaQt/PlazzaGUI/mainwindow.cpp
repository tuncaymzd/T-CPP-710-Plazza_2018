#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QStringList>
#include <string>
#include <QFileDialog>
#include <QInputDialog>

using std::string;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->runButton, &QPushButton::clicked, this, &MainWindow::runClicked);
    connect(ui->browseButton, &QPushButton::clicked, this, &MainWindow::browseButtonClicked);
    connect(ui->kitchenButton, &QPushButton::clicked, this, &MainWindow::setKitchenClicked);
    connect(ui->cookButton, &QPushButton::clicked, this, &MainWindow::setCookerClicked);
    connect(ui->setTimeButton, &QPushButton::clicked, this, &MainWindow::setTimeClicked);
    QStringList stringList;
     ui->filePathLineEdit->setEnabled(false);
    ui->cookerLineEdit->setEnabled(false);
    ui->kitchenLineEdit->setEnabled(false);
    ui->timeLineEdit->setEnabled(false);
    ui->lineEdit->setVisible(false);
    model = new QStringListModel();
    model->setStringList(stringList);
    ui->cookingListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->cookingListView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTimeClicked()
{
    bool ok;
    int time = QInputDialog::getInt(this, tr("Get the Time."),
                                      tr("Cooking Time"), 0, 0, 2147483647, 1, &ok);
    if(ok)
    {
        timeCount = time;
         ui->timeLineEdit->setText(QString::number(time));
    }
}

void MainWindow::setCookerClicked()
{
    bool ok;
    int cooker = QInputDialog::getInt(this, tr("Get the Time."),
                                      tr("Cooking Time"), 0, 0, 100, 1, &ok);
    if(ok)
    {
        cookerCount = cooker;
        ui->cookerLineEdit->setText(QString::number(cooker));
    }
}

void MainWindow::setKitchenClicked()
{
    bool ok;
    int kitchen = QInputDialog::getInt(this, tr("Get the Time."),
                                      tr("Cooking Time"), 0, 0, 100, 1, &ok);
    if(ok)
    {
        kitchenCount = kitchen;
        ui->kitchenLineEdit->setText(QString::number(kitchen));
    }
}

void MainWindow::browseButtonClicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home/", tr("Image Files (*.txt)"));
    ui->filePathLineEdit->setText(fileName);
    configFile = fileName.toUtf8().constData();
}

void MainWindow::runClicked()
{
    if(cookerCount == 0 && kitchenCount == 0 && timeCount == 0 && configFile == "")
    {
        QMessageBox::about(this, "Beware!", "Please enter ALL configurations parameters before running the application.");
        return;
    }
    runProcesses();
//    populateListView(ui->lineEdit->text().toUtf8().constData());
//    ui->lineEdit->clear();
}

void MainWindow::runProcesses()
{
        c = new Controleur();
        std::queue<Command> listOfCommands;

        try {
            c->setNumbersOfCooker(cookerCount);
            c->setNumbersOfKitchens(kitchenCount);
            c->setBaseTime(timeCount);
            c->readFile(configFile);
            listOfCommands = c->getTheCommands();
            Dispatcher::initialize(kitchenCount, cookerCount, timeCount, listOfCommands);
            Dispatcher::splitTheCommands();
            Dispatcher::setOnNotify(notif);
            Dispatcher::createKitchens();
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
}

void MainWindow::populateListView(string message)
{
    model->insertRow(model->rowCount());
    QModelIndex index = model->index(model->rowCount() - 1);
    model->setData(index, QString::fromStdString(message));
}
