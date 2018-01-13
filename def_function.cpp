#include "mainwindow.h"
#include "ui_mainwindow.h"

int MainWindow::day_number_in_year(int year, int month, int day)
{
    int day_number = 0;

    int days_in_month[13];
    days_in_month[0] = 0;
    days_in_month[1] = 31;
    if (year % 4 == 0)
        days_in_month[2] = 29;
    else
        days_in_month[2] = 28;
    days_in_month[3] = 31;
    days_in_month[4] = 30;
    days_in_month[5] = 31;
    days_in_month[6] = 30;
    days_in_month[7] = 31;
    days_in_month[8] = 31;
    days_in_month[9] = 30;
    days_in_month[10] = 31;
    days_in_month[11] = 30;
    days_in_month[12] = 31;

    for (int i=1; i<month; i++)
    {
        day_number += days_in_month[i];
    }
    day_number += day;
    return day_number;
}

int MainWindow::run_num_between_years(int start_year, int end_year)
{
    int run_num = 0;
    for (int i = start_year; i<end_year; i++)
    {
        if (i%4 == 0)
            run_num++;
    }
    return run_num;
}

int MainWindow::day_num_between_days(int start_year, int start_month, int start_day, int end_year, int end_month, int end_day)
{
    int start_day_number  = day_number_in_year(start_year, start_month, start_day);
    int end_day_number    = day_number_in_year(end_year,   end_month,   end_day);
    int run_num = run_num_between_years(start_year, end_year);
    int day_num = run_num*366 + (end_year-start_year-run_num)*365 + (end_day_number - start_day_number);
    return day_num;
}

void MainWindow::show_time(QLabel *label, char mode, int year_hour, int month_minute, int day_second)
{     
    switch (mode)
    {
    case 't':   //时间
        if (year_hour < 10)//若分钟数比9小，如17点1分，使17:1显示为17:01
            if (month_minute < 10)
                label->setText(tr("0%1:0%2").arg(year_hour).arg(month_minute));
            else
                label->setText(tr("0%1:%2").arg(year_hour).arg(month_minute));
        else
            if (month_minute < 10)
                label->setText(tr("%1:0%2").arg(year_hour).arg(month_minute));
            else
                label->setText(tr("%1:%2").arg(year_hour).arg(month_minute));
        break;
    case 'd':   //日期
        if (month_minute < 10)
            if (day_second < 10)
                label->setText(tr("%1/0%2/0%3").arg(year_hour).arg(month_minute).arg(day_second));
            else
                label->setText(tr("%1/0%2/%3").arg(year_hour).arg(month_minute).arg(day_second));
        else
            if (day_second < 10)
                label->setText(tr("%1/%2/0%3").arg(year_hour).arg(month_minute).arg(day_second));
            else
                label->setText(tr("%1/%2/%3").arg(year_hour).arg(month_minute).arg(day_second));
        break;
    default:
        break;
    }
}
