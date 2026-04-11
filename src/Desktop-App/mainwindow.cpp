#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set window size to take up whole screen with borders
    this->setWindowState(Qt::WindowMaximized);

    connect(ui->dashboardPushButton, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->dashboardPage);
        std::cout << "Dashboard Page" << std::endl;
    });
    connect(ui->catalogPushButton, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->catalogPage);
        std::cout << "Catalog Page" << std::endl;
    });
    connect(ui->managePushButton, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->managePage);
        std::cout << "Manage Page" << std::endl;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
