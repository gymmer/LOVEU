#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "settime.h"
#include "setmemory.h"
#include "info.h"
#include "usage.h"
#include <QLabel>
#include <QDate>
#include <QTime>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QMenu>
#include <QContextMenuEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //在def_system.cpp中实现
    void contextMenuEvent(QContextMenuEvent *event);                //右键菜单
    void value_time();                                              //为倒计时赋值
    void value_memory();                                            //为纪念日赋值

    //在def_function.cpp中实现
    int day_number_in_year(int year,int month, int day);            //输入的日期，是当年的第几天
    int run_num_between_years(int start_year, int end_year);        //输入的年份中，有多少个闰年
    int day_num_between_days(int start_year, int start_month, int start_day, int end_year, int end_month, int end_day);
                                                                    //输入的起止日期内，有多少天
    void show_time(QLabel *label, char flag, int year_hour, int month_hour, int day_minute);
                                                                    //显示输入的日期或时间。flag='t'，时间。'd'，日期。

private slots:
    //在def_triggered.cpp中实现
    void on_quit_triggered();
    void on_settime_triggered();
    void on_setmemory_triggered();
    void on_rfreshtime_triggered();
    void on_rfreshmemory_triggered();
    void on_about_triggered();
    void on_usage_triggered();
    //在def_system.cpp中实现
    void refresh_time();                                            //刷新倒计时
    void refresh_memory();                                          //刷新纪念日

private:
    Ui::MainWindow *ui;

    int now_year;
    int now_month;
    int now_day;
    int now_hour;
    int now_minute;

    int back_year;
    int back_month;
    int back_day;
    int back_hour;
    int back_minute;

    int mode;   //倒计时模式。0：小时。1：天

    int toge_year;
    int toge_month;
    int toge_day;
    int hand_year;
    int hand_month;
    int hand_day;
    int hug_year;
    int hug_month;
    int hug_day;
    int kiss_year;
    int kiss_month;
    int kiss_day;
    int trip_year;
    int trip_month;
    int trip_day;
};

#endif // MAINWINDOW_H
