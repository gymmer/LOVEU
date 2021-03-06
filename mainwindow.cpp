#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    ui->textBrowser->setVisible(false);
    setWindowTitle("LoveU");

    value_time();
    value_memory();
    value_birthday();
    value_weather();
    value_word();
    refresh_time();
    refresh_memory();
    refresh_birthday();
    refresh_weather();
    refresh_word();
}

MainWindow::~MainWindow()
{
    delete ui;
}
