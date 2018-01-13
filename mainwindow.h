#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "settime.h"
#include "setmemory.h"
#include "setbirthday.h"
#include "setweather.h"
#include "setword.h"
#include "info.h"
#include "usage.h"
#include "citymanager.h"
#include "XorEncryptDecrypt.h"

#include <QLabel>
#include <QDate>
#include <QTime>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QMenu>
#include <QContextMenuEvent>
#include <string>

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
    void value_birthday();                                          //为生日赋值
    void value_weather();                                           //为所在城市赋值，以读取该城市天气
    void show_weather(const QStringList &strList);                  //显示天气
    void value_word();                                              //为留言赋值

    //在def_function.cpp中实现
    int day_number_in_year(int year,int month, int day);             //输入的日期，是当年的第几天
    int run_num_between_years(int start_year, int end_year);         //输入的年份中，有多少个闰年
    int day_num_between_days(int start_year, int start_month, int start_day, int end_year, int end_month, int end_day);
                                                                     //输入的起止日期内，有多少天
    QDate conver_from_yang_to_yin(int gyear, int gmonth, int gday);  //阳历转换为阴历
    QDate conver_from_yin_to_yang(int nyear, int nmonth, int nday);  //阴历转换为阳历
    void show_time(QLabel *label, char flag, int year_hour, int month_hour, int day_minute);
                                                                     //显示输入的日期或时间。flag='t'，时间。'd'，日期。'y'，阴历
    void show_birthday(QLabel *label, char flag, int month, int day);
                                                                     //显示生日。flag='i'，阴历。flag='a'，阳历。

private slots:
    //在def_triggered.cpp中实现
    void on_quit_triggered();
    void on_settime_triggered();
    void on_setmemory_triggered();
    void on_setbirthday_triggered();
    void on_setweather_triggered();
    void on_setword_triggered();
    void on_rfreshtime_triggered();
    void on_rfreshmemory_triggered();
    void on_rfreshbirthday_triggered();
    void on_rfreshweather_triggered();
    void on_rfreshword_triggered();
    void on_selectword_triggered();
    void on_about_triggered();
    void on_usage_triggered();

    //在def_toolButton.cpp中实现
    void on_refresh_time_toolButton_clicked();
    void on_set_time_toolButton_clicked();
    void on_refresh_memory_toolButton_clicked();
    void on_set_memory_toolButton_clicked();
    void on_refresh_birthday_toolButton_clicked();
    void on_set_birthday_toolButton_clicked();
    void on_refresh_weather_toolButton_clicked();
    void on_set_weather_toolButton_clicked();
    void on_select_person_comboBox_currentIndexChanged(int index);
    void on_toolButton_toggled(bool checked);
    void on_refresh_word_toolButton_clicked();
    void on_set_word_toolButton_clicked();
    void on_select_word_toolButton_clicked();

    //在def_system.cpp中实现
    void refresh_time();        //刷新倒计时
    void refresh_memory();      //刷新纪念日
    void refresh_birthday();    //刷新生日
    void refresh_weather();     //刷新天气
    void refresh_word();        //刷新留言

private:
    Ui::MainWindow *ui;

    //倒计时
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

    int time_mode;   //倒计时模式。0：小时。1：天

    //纪念日
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

    //生日
    int my_birthday_month;
    int my_birthday_day;
    int her_birthday_month;
    int her_birthday_day;

    int birthday_mode; //生日模式。0：农历/阴历。1：公元/阳历

    //天气
    QString my_city;
    QString her_city;
    CityManager my_cityManager;
    CityManager her_cityManager;

    //留言
    QString word_fileName;
    QString word_str;

};

#endif // MAINWINDOW_H
