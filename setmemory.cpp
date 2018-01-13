#include "setmemory.h"
#include "ui_setmemory.h"
#include <QDate>
#include <QFile>
#include <QTextStream>
#include <QDebug>

setmemory::setmemory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setmemory)
{
    ui->setupUi(this);
    setWindowTitle("设置");

    QDate current_date = QDate::currentDate();
    ui->toge_dateEdit->setMaximumDate(current_date);
    ui->hand_dateEdit->setMaximumDate(current_date);
    ui->hug_dateEdit ->setMaximumDate(current_date);
    ui->kiss_dateEdit->setMaximumDate(current_date);
    ui->trip_dateEdit->setMaximumDate(current_date);

    QDate toge_date;
    QDate hand_date;
    QDate hug_date;
    QDate kiss_date;
    QDate trip_date;

    //以只读方式打开配置文件memory.txt
    QFile file("memory.txt");
    if (!file.open(QIODevice::ReadOnly | QFile::Text))  //无配置文件，显示当前时间
    {
        int current_year   = current_date.year();
        int current_month  = current_date.month();
        int current_day    = current_date.day();

        toge_date.setDate(current_year, current_month, current_day);
        hand_date.setDate(current_year, current_month, current_day);
        hug_date.setDate (current_year, current_month, current_day);
        kiss_date.setDate(current_year, current_month, current_day);
        trip_date.setDate(current_year, current_month, current_day);
    }
    else    //读取配置文件成功
    {
        QTextStream in(&file);
        int toge_year  = in.readLine().toInt();
        int toge_month = in.readLine().toInt();
        int toge_day   = in.readLine().toInt();
        int hand_year  = in.readLine().toInt();
        int hand_month = in.readLine().toInt();
        int hand_day   = in.readLine().toInt();
        int hug_year   = in.readLine().toInt();
        int hug_month  = in.readLine().toInt();
        int hug_day    = in.readLine().toInt();
        int kiss_year  = in.readLine().toInt();
        int kiss_month = in.readLine().toInt();
        int kiss_day   = in.readLine().toInt();
        int trip_year  = in.readLine().toInt();
        int trip_month = in.readLine().toInt();
        int trip_day   = in.readLine().toInt();

        toge_date.setDate(toge_year, toge_month, toge_day);
        hand_date.setDate(hand_year, hand_month, hand_day);
        hug_date.setDate (hug_year,  hug_month,  hug_day);
        kiss_date.setDate(kiss_year, kiss_month, kiss_day);
        trip_date.setDate(trip_year, trip_month, trip_day);

        file.close();
    }

    ui->toge_dateEdit->setDate(toge_date);
    ui->hand_dateEdit->setDate(hand_date);
    ui->hug_dateEdit ->setDate(hug_date);
    ui->kiss_dateEdit->setDate(kiss_date);
    ui->trip_dateEdit->setDate(trip_date);
}

setmemory::~setmemory()
{
    delete ui;
}

void setmemory::on_save_pushButton_clicked()
{
    QDate toge_date = ui->toge_dateEdit->date();
    QDate hand_date = ui->hand_dateEdit->date();
    QDate hug_date  = ui->hug_dateEdit ->date();
    QDate kiss_date = ui->kiss_dateEdit->date();
    QDate trip_date = ui->trip_dateEdit->date();

    //以只写方式打开文件。若文件不存在，那么创建文件memory.txt
    QFile file("memory.txt");
    if (!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        qDebug() << endl << file.errorString();
    }
    QTextStream out(&file);
    out << toge_date.year() << endl << toge_date.month() << endl << toge_date.day() << endl
        << hand_date.year() << endl << hand_date.month() << endl << hand_date.day() << endl
        << hug_date.year()  << endl << hug_date.month()  << endl << hug_date.day()  << endl
        << kiss_date.year() << endl << kiss_date.month() << endl << kiss_date.day() << endl
        << trip_date.year() << endl << trip_date.month() << endl << trip_date.day();
    file.close();
    close();
}

void setmemory::on_cancel_pushButton_clicked()
{
    close();
}
