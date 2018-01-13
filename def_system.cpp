#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu *menu = new QMenu(this);
    menu->addAction(ui->rfreshtime);
    menu->addAction(ui->rfreshmemory);
    menu->addSeparator();
    menu->addAction(ui->settime);
    menu->addAction(ui->setmemory);
    menu->addSeparator();
    menu->addAction(ui->quit);
    menu->exec(this->cursor().pos()); //让菜单显示的位置在鼠标的坐标上
    event->accept();
}

void MainWindow::value_time()
{
    //现在日期及时间。系统当前时间得到
    QDate now_date = QDate::currentDate();
    QTime now_time = QTime::currentTime();
    now_year   = now_date.year();
    now_month  = now_date.month();
    now_day    = now_date.day();
    now_hour   = now_time.hour();
    now_minute = now_time.minute();

    //归来日期及时间。读取配置文件得到
    QFile file("time.txt");
    if (!file.open(QIODevice::ReadOnly | QFile::Text))  //无配置文件
    {
        back_year   = now_year;
        back_month  = now_month;
        back_day    = now_day;
        back_hour   = now_hour;
        back_minute = now_minute;
        mode        = 0;

    }
    else    //读取配置文件成功
    {
        QTextStream in(&file);
        back_year   = in.readLine().toInt();
        back_month  = in.readLine().toInt();
        back_day    = in.readLine().toInt();
        back_hour   = in.readLine().toInt();
        back_minute = in.readLine().toInt();
        mode        = in.readLine().toInt();
        file.close();
    }
}

void MainWindow::value_memory()
{
    //纪念日。读取配置文件得到
    QFile file2("memory.txt");
    if (!file2.open(QIODevice::ReadOnly | QFile::Text))  //无配置文件
    {
        QDate current_date = QDate::currentDate();
        toge_year  = current_date.year();
        toge_month = current_date.month();
        toge_day   = current_date.day();
        hand_year  = current_date.year();
        hand_month = current_date.month();
        hand_day   = current_date.day();
        hug_year   = current_date.year();
        hug_month  = current_date.month();
        hug_day    = current_date.day();
        kiss_year  = current_date.year();
        kiss_month = current_date.month();
        kiss_day   = current_date.day();
        trip_year  = current_date.year();
        trip_month = current_date.month();
        trip_day   = current_date.day();
    }
    else    //读取配置文件成功
    {
        QTextStream in(&file2);
        toge_year  = in.readLine().toInt();
        toge_month = in.readLine().toInt();
        toge_day   = in.readLine().toInt();
        hand_year  = in.readLine().toInt();
        hand_month = in.readLine().toInt();
        hand_day   = in.readLine().toInt();
        hug_year   = in.readLine().toInt();
        hug_month  = in.readLine().toInt();
        hug_day    = in.readLine().toInt();
        kiss_year  = in.readLine().toInt();
        kiss_month = in.readLine().toInt();
        kiss_day   = in.readLine().toInt();
        trip_year  = in.readLine().toInt();
        trip_month = in.readLine().toInt();
        trip_day   = in.readLine().toInt();
        file2.close();
    }
}

void MainWindow::refresh_time()
{
    int day_num = day_num_between_days(now_year, now_month, now_day, back_year, back_month, back_day);

    switch (mode)
    {
    case 0: //倒计时模式：小时
    {
        int hour_num = day_num * 24 + (back_hour - now_hour);
        ui->time_num_label->setText(tr("%1").arg(hour_num));
        ui->mode_label->setText("小时！");
        break;
    }
    case 1: //倒计时模式：天
    {
        ui->time_num_label->setText(tr("%1").arg(day_num));
        ui->mode_label->setText("天！");
        break;
    }
    default:
        break;
    }
    show_time(ui->now_date_label,  'd', now_year,  now_month,  now_day);
    show_time(ui->back_date_label, 'd', back_year, back_month, back_day);
    show_time(ui->now_time_label,  't', now_hour,  now_minute, 0);
    show_time(ui->back_time_label, 't', back_hour, back_minute,0);
}

void MainWindow::refresh_memory()
{
    int toge_day_num = day_num_between_days(toge_year, toge_month, toge_day, now_year, now_month, now_day);
    int hand_day_num = day_num_between_days(hand_year, hand_month, hand_day, now_year, now_month, now_day);
    int hug_day_num  = day_num_between_days(hug_year,  hug_month,  hug_day,  now_year, now_month, now_day);
    int kiss_day_num = day_num_between_days(kiss_year, kiss_month, kiss_day, now_year, now_month, now_day);
    int trip_day_num = day_num_between_days(trip_year, trip_month, trip_day, now_year, now_month, now_day);

    ui->toge_num_label->setText(tr("%1").arg(toge_day_num));
    ui->hand_num_label->setText(tr("%1天").arg(hand_day_num));
    ui->hug_num_label ->setText(tr("%1天").arg(hug_day_num ));
    ui->kiss_num_label->setText(tr("%1天").arg(kiss_day_num));
    ui->trip_num_label->setText(tr("%1天").arg(trip_day_num));

    show_time(ui->hand_date_label, 'd', hand_year, hand_month, hand_day);
    show_time(ui->hug_date_label,  'd', hug_year,  hug_month,  hug_day);
    show_time(ui->kiss_date_label, 'd', kiss_year, kiss_month, kiss_day);
    show_time(ui->trip_date_label, 'd', trip_year, trip_month, trip_day);
}
