#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_quit_triggered()
{
    exit(1);
}

void MainWindow::on_settime_triggered()
{
    settime *setime_window = new settime(this);
    setime_window->show();
    connect(setime_window,SIGNAL(finished(int)),this,SLOT(on_rfreshtime_triggered()));
}

void MainWindow::on_setmemory_triggered()
{
    setmemory *setmemory_window = new setmemory(this);
    setmemory_window->show();
    connect(setmemory_window,SIGNAL(finished(int)),this,SLOT(on_rfreshmemory_triggered()));
}

void MainWindow::on_setbirthday_triggered()
{
    setbirthday *setbirthday_window = new setbirthday(this);
    setbirthday_window->show();
    connect(setbirthday_window,SIGNAL(finished(int)),this,SLOT(on_rfreshbirthday_triggered()));
}

void MainWindow::on_setweather_triggered()
{
    setweather *setweather_window = new setweather(this);
    setweather_window->show();
    connect(setweather_window,SIGNAL(finished(int)),this,SLOT(on_rfreshweather_triggered()));
}

void MainWindow::on_rfreshtime_triggered()
{
    value_time();
    refresh_time();
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_rfreshmemory_triggered()
{
    value_memory();
    refresh_memory();
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_rfreshbirthday_triggered()
{
    value_birthday();
    refresh_birthday();
    ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_rfreshweather_triggered()
{
    value_weather();
    refresh_weather();
    ui->tabWidget->setCurrentIndex(3);
}

void MainWindow::on_about_triggered()
{
    info *info_window = new info(this);
    info_window->show();
}

void MainWindow::on_usage_triggered()
{
    usage *usage_window = new usage(this);
    usage_window->show();
}
