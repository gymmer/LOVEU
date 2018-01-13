#include "settime.h"
#include "ui_settime.h"
#include <QDate>
#include <QTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>

settime::settime(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settime)
{
    ui->setupUi(this);
    setWindowTitle("设置");

    QDate current_date = QDate::currentDate();
    QTime current_time = QTime::currentTime();
    ui->dateEdit->setMinimumDate(current_date);

    QDate back_date;
    QTime back_time;

    //以只读方式打开配置文件time.txt
    QFile file("time.txt");
    if (!file.open(QIODevice::ReadOnly | QFile::Text))  //无配置文件，显示当前时间
    {
        back_date.setDate(current_date.year(), current_date.month(), current_date.day());
        back_time.setHMS (current_time.hour(), current_time.minute(),0);
    }
    else    //读取配置文件成功
    {
        QTextStream in(&file);
        int back_year   = in.readLine().toInt();
        int back_month  = in.readLine().toInt();
        int back_day    = in.readLine().toInt();
        int back_hour   = in.readLine().toInt();
        int back_minute = in.readLine().toInt();
        back_date.setDate(back_year, back_month, back_day);
        back_time.setHMS(back_hour,back_minute,0);
        file.close();
    }

    ui->dateEdit->setDate(back_date);
    ui->timeEdit->setTime(back_time);
}

settime::~settime()
{
    delete ui;
}

void settime::on_save_pushButton_clicked()
{
    QDate back_date = ui->dateEdit->date();
    QTime back_time = ui->timeEdit->time();
    int back_year   = back_date.year();
    int back_month  = back_date.month();
    int back_day    = back_date.day();
    int back_hour   = back_time.hour();
    int back_minute = back_time.minute();

    //以只写方式打开文件。若文件不存在，那么创建文件time.txt
    QFile file("time.txt");
    if (!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        qDebug() << endl << file.errorString();
    }
    QTextStream out(&file);
    out << back_year << endl << back_month << endl << back_day << endl
        << back_hour << endl << back_minute;
    file.close();
    close();
}

void settime::on_cancle_pushButton_clicked()
{
    close();
}
