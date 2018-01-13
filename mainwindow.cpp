#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    setWindowTitle("LoveU");

    //改变标签页，自动刷新
    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(refresh_time()));
    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(refresh_memory()));

    value_time();
    value_memory();
    refresh_time();
    refresh_memory();
}

MainWindow::~MainWindow()
{
    delete ui;
}


