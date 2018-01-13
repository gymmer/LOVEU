#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::on_refresh_time_toolButton_clicked()
{
    refresh_time();
}

void MainWindow::on_set_time_toolButton_clicked()
{
    on_settime_triggered();
}

void MainWindow::on_refresh_memory_toolButton_clicked()
{
    refresh_memory();
}

void MainWindow::on_set_memory_toolButton_clicked()
{
    on_setmemory_triggered();
}

void MainWindow::on_refresh_birthday_toolButton_clicked()
{
    refresh_birthday();
}

void MainWindow::on_set_birthday_toolButton_clicked()
{
    on_setbirthday_triggered();
}

void MainWindow::on_refresh_weather_toolButton_clicked()
{
    on_rfreshweather_triggered();
}

void MainWindow::on_set_weather_toolButton_clicked()
{
    on_setweather_triggered();
}

void MainWindow::on_toolButton_toggled(bool checked)
{
    ui->textBrowser->setVisible(checked);
}

void MainWindow::on_select_person_comboBox_currentIndexChanged(int index)
{
    refresh_weather();
}
