#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settime.h"
#include "info.h"
#include "help.h"
#include <QLabel>
#include <QDate>
#include <QTime>
#include <QDebug>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("LoveU");
    QLabel *lable = new QLabel(this);   //显示永久消息
    lable->setText("给最爱的Darling");
    lable->setFrameStyle(QFrame::Sunken);
    ui->statusBar->addPermanentWidget(lable);

    QDate now_date = QDate::currentDate();
    QTime now_time = QTime::currentTime();
    now_year = now_date.year();
    now_month = now_date.month();
    now_day = now_date.day();
    now_hour = now_time.hour();
    now_minute = now_time.minute();

    //以只读方式打开配置文件Setting.txt
    QFile file("Setting.txt");
    if (!file.open(QIODevice::ReadOnly | QFile::Text))  //无配置文件
    {
        back_year = now_year;
        back_month = now_month;
        back_day = now_day;
        back_hour = now_hour;
        back_minute = now_minute;
    }
    else    //读取配置文件成功
    {
        QTextStream in(&file);
        back_year= in.readLine().toInt();
        back_month = in.readLine().toInt();
        back_day = in.readLine().toInt();
        back_hour = in.readLine().toInt();
        back_minute = in.readLine().toInt();
        file.close();
    }

    int day_num;
    int hour_num;
    if (back_hour >= now_hour)
    {
        day_num = back_day - now_day;
        hour_num = day_num * 24 + (back_hour - now_hour);
    }
    else
    {
        day_num = back_day - now_day - 1;
        hour_num = day_num * 24 + (24 + (back_hour-now_hour));
    }
    ui->hour_num_label->setText(tr("%1").arg(hour_num));
    //若分钟数比9小，如17点1分，使17:1显示为17:01
    if (now_minute <= 9)
    {
        ui->now_time_label->setText(tr("%1.%2.%3 %4:0%5")
                                    .arg(now_year).arg(now_month).arg(now_day).arg(now_hour).arg(now_minute));
    }
    else
    {
        ui->now_time_label->setText(tr("%1.%2.%3 %4:%5")
                                    .arg(now_year).arg(now_month).arg(now_day).arg(now_hour).arg(now_minute));
    }
    if (back_minute <= 9)
    {
        ui->back_time_label->setText(tr("%1.%2.%3 %4:0%5")
                                    .arg(back_year).arg(back_month).arg(back_day).arg(back_hour).arg(back_minute));
    }
    else
    {
        ui->back_time_label->setText(tr("%1.%2.%3 %4:%5")
                                    .arg(back_year).arg(back_month).arg(back_day).arg(back_hour).arg(back_minute));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_quit_triggered()
{
    exit(1);
}

void MainWindow::on_settime_triggered()
{
    settime *setime_window = new settime(this);
    setime_window->show();
}

void MainWindow::on_rfresh_triggered()
{
    QDate now_date = QDate::currentDate();
    QTime now_time = QTime::currentTime();
    now_year = now_date.year();
    now_month = now_date.month();
    now_day = now_date.day();
    now_hour = now_time.hour();
    now_minute = now_time.minute();

    //以只读方式打开配置文件Setting.txt
    QFile file("Setting.txt");
    if (!file.open(QIODevice::ReadOnly | QFile::Text))  //无配置文件
    {
        back_year = now_year;
        back_month = now_month;
        back_day = now_day;
        back_hour = now_hour;
        back_minute = now_minute;
    }
    else    //读取配置文件成功
    {
        QTextStream in(&file);
        back_year= in.readLine().toInt();
        back_month = in.readLine().toInt();
        back_day = in.readLine().toInt();
        back_hour = in.readLine().toInt();
        back_minute = in.readLine().toInt();
        file.close();
    }

    int day_num;
    int hour_num;
    if (back_hour >= now_hour)
    {
        day_num = back_day - now_day;
        hour_num = day_num * 24 + (back_hour - now_hour);
    }
    else
    {
        day_num = back_day - now_day - 1;
        hour_num = day_num * 24 + (24 + (back_hour-now_hour));
    }
    ui->hour_num_label->setText(tr("%1").arg(hour_num));
    //若分钟数比9小，如17点1分，使17:1显示为17:01
    if (now_minute <= 9)
    {
        ui->now_time_label->setText(tr("%1.%2.%3 %4:0%5")
                                    .arg(now_year).arg(now_month).arg(now_day).arg(now_hour).arg(now_minute));
    }
    else
    {
        ui->now_time_label->setText(tr("%1.%2.%3 %4:%5")
                                    .arg(now_year).arg(now_month).arg(now_day).arg(now_hour).arg(now_minute));
    }
    if (back_minute <= 9)
    {
        ui->back_time_label->setText(tr("%1.%2.%3 %4:0%5")
                                    .arg(back_year).arg(back_month).arg(back_day).arg(back_hour).arg(back_minute));
    }
    else
    {
        ui->back_time_label->setText(tr("%1.%2.%3 %4:%5")
                                    .arg(back_year).arg(back_month).arg(back_day).arg(back_hour).arg(back_minute));
    }
}

void MainWindow::on_about_triggered()
{
    info *info_window = new info(this);
    info_window->show();
}

void MainWindow::on_help_triggered()
{
    help *help_window = new help(this);
    help_window->show();
}
