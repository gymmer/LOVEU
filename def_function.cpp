#include "mainwindow.h"
#include "ui_mainwindow.h"

int MainWindow::day_number_in_year(int year, int month, int day)
{
    int day_number = 0;

    int days_in_month[13];
    days_in_month[0] = 0;
    days_in_month[1] = 31;
    if (year%4==0 && year%100!=0 || year%400==0)
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
        if (i%4==0 && i%100!=0 || i%400==0)
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

/*公历每月前面的天数*/
const int gPastday[13] = {0,0,31,59,90,120,151,181,212,243,273,304,334};
int months[13] = {0,31,0,31,30,31,30,31,31,30,31,30,31};
const long NongliData[202]= {0xAB500D2,0x4BD0883,
0x4AE00DB,0xA5700D0,0x54D0581,0xD2600D8,0xD9500CC,0x655147D,0x56A00D5,0x9AD00CA,0x55D027A,0x4AE00D2,
0xA5B0682,0xA4D00DA,0xD2500CE,0xD25157E,0xB5500D6,0x56A00CC,0xADA027B,0x95B00D3,0x49717C9,0x49B00DC,
0xA4B00D0,0xB4B0580,0x6A500D8,0x6D400CD,0xAB5147C,0x2B600D5,0x95700CA,0x52F027B,0x49700D2,0x6560682,
0xD4A00D9,0xEA500CE,0x6A9157E,0x5AD00D6,0x2B600CC,0x86E137C,0x92E00D3,0xC8D1783,0xC9500DB,0xD4A00D0,
0xD8A167F,0xB5500D7,0x56A00CD,0xA5B147D,0x25D00D5,0x92D00CA,0xD2B027A,0xA9500D2,0xB550781,0x6CA00D9,
0xB5500CE,0x535157F,0x4DA00D6,0xA5B00CB,0x457037C,0x52B00D4,0xA9A0883,0xE9500DA,0x6AA00D0,0xAEA0680,
0xAB500D7,0x4B600CD,0xAAE047D,0xA5700D5,0x52600CA,0xF260379,0xD9500D1,0x5B50782,0x56A00D9,0x96D00CE,
0x4DD057F,0x4AD00D7,0xA4D00CB,0xD4D047B,0xD2500D3,0xD550883,0xB5400DA,0xB6A00CF,0x95A1680,0x95B00D8,
0x49B00CD,0xA97047D,0xA4B00D5,0xB270ACA,0x6A500DC,0x6D400D1,0xAF40681,0xAB600D9,0x93700CE,0x4AF057F,
0x49700D7,0x64B00CC,0x74A037B,0xEA500D2,0x6B50883,0x5AC00DB,0xAB600CF,0x96D0580,0x92E00D8,0xC9600CD,
0xD95047C,0xD4A00D4,0xDA500C9,0x755027A,0x56A00D1,0xABB0781,0x25D00DA,0x92D00CF,0xCAB057E,0xA9500D6,
0xB4A00CB,0xBAA047B,0xB5500D2,0x55D0983,0x4BA00DB,0xA5B00D0,0x5171680,0x52B00D8,0xA9300CD,0x795047D,
0x6AA00D4,0xAD500C9,0x5B5027A,0x4B600D2,0x96E0681,0xA4E00D9,0xD2600CE,0xEA6057E,0xD5300D5,0x5AA00CB,
0x76A037B,0x96D00D3,0x4AB0B83,0x4AD00DB,0xA4D00D0,0xD0B1680,0xD2500D7,0xD5200CC,0xDD4057C,0xB5A00D4,
0x56D00C9,0x55B027A,0x49B00D2,0xA570782,0xA4B00D9,0xAA500CE,0xB25157E,0x6D200D6,0xADA00CA,0x4B6137B,
0x93700D3,0x49F08C9,0x49700DB,0x64B00D0,0x68A1680,0xEA500D7,0x6AA00CC,0xA6C147C,0xAAE00D4,0x92E00CA,
0xD2E0379,0xC9600D1,0xD550781,0xD4A00D9,0xDA400CD,0x5D5057E,0x56A00D6,0xA6C00CB,0x55D047B,0x52D00D3,
0xA9B0883,0xA9500DB,0xB4A00CF,0xB6A067F,0xAD500D7,0x55A00CD,0xABA047C,0xA5A00D4,0x52B00CA,0xB27037A,
0x69300D1,0x7330781,0x6AA00D9,0xAD500CE,0x4B5157E,0x4B600D6,0xA5700CB,0x54E047C,0xD1600D2,0xE960882,
0xD5200DA,0xDAA00CF,0x6AA167F,0x56D00D7,0x4AE00CD,0xA9D047D,0xA2D00D4,0xD1500C9,0xF250279,0xD5200D1};

QDate MainWindow::conver_from_yang_to_yin(int gyear, int gmonth, int gday)
{
    static int whatday, a, b, whatChunJie, gong_chunjie, Znongwhatday;
    static int nYear, nMonth, nDay, runmonth, runday, YNrun=0, runt;
    long int ChunJieYear;
    long int c;
    int wei, wei1, cz, cz1, nm, mt, i, i1;

    if (gyear%4==0 && gyear%100!=0 || gyear%400==0)
        months[2] = 29;
    else
        months[2] = 28;

    /*以下是计算在该公历年的第几天.  如果是闰年和月份大于二则在该公历年的第几天数+1*/
    whatday = gPastday[gmonth] + gday;
    if ((gyear%4==0 && gyear%100!=0 || gyear%400==0) && (gmonth>2))
        whatday++;

    /*计算该年春节在公历年的第几天*/
   ChunJieYear = NongliData[gyear-1899]; /*ChunJieYear 春节的农历数据*/
   b = 0x100;
   a = ChunJieYear%b; /*取出春节在公历几月几日的十六进制数*/
   whatChunJie=gPastday[a/100]+a%100;  /*春节在公历年的第几天=月的天数+日数*/
    if ((ChunJieYear%4==0 && ChunJieYear%100!=0 || ChunJieYear%400==0) && (a/100>2))
        whatChunJie++;
      /*如果是闰年&&月份大于二则在该公历年的第几天数+1*/
    gong_chunjie = whatday - (whatChunJie-1); /*差值=输入的公历日期-春节在公历年的第几天-1*/

    if (gong_chunjie > 0)
     {
        nYear = gyear;
        Znongwhatday = gong_chunjie;   /*变量Znongwhatday 输入的公历日期在农历年第几天*/
     }                             /*由差值判断农历年nYear*/
   else
    {
        nYear = gyear - 1;
        Znongwhatday = gong_chunjie;   /*变量Znongwhatday 输入的公历日期在农历年第几天*/
    }

   runday = (NongliData[nYear-1899]/0x1000)%0x10;    /*取出判断闰月天数的值*/
   runmonth = (NongliData[nYear-1899]/0x100)%0x10;   /*取出判断是否闰月闰几月的值*/
   c = NongliData[nYear-1899]/0x10000;   /*变量C 农历12个月的天数十六进制数据*/
    if (Znongwhatday > 0)      /*如果公历年与农历年相同*/
    {
        cz = Znongwhatday;      /*将变量Znongwhatday的值辅给变量cz*/
        wei = 11;               /*wei 位运算移动的值*/
        nm = 0;                 /*nm 存放农历月值的变量*/

       while (wei >= 0)
       {
            i = c>>wei&~(~0<<1);
            if (i == 1)
                mt = 30;
            else
                mt = 29;         /*逐月取出月的值判断天数,计算月的值*/
            if (runday == 1)
                runt = 30;
            else
                runt = 29;
            cz = cz - mt;
            if (cz <= 0)  /*计算农历日的值*/
            {
                nm++;
                nDay = cz + mt;
                break;
            }
            nm++;
            if (nm == runmonth)
            {
                cz = cz - runt;
                if (cz <= 0)/*闰月时的情况*/
                {
                    nDay = cz + runt;
                    YNrun = 1;
                    break;
                }
            }
        wei--;
        }
    }

    if (Znongwhatday  <=  0) /*如果农历年=公历年-1*/
    {
        cz1 = Znongwhatday;
        wei1 = 0;
        nm = 13;
        while (wei1 <= 11)
        {
             i1= c>>wei1&~(~0<<1);

            if (i1 == 1)
                mt = 30;
           else
                mt = 29;

            if (runday == 1)
                runt = 30;
           else
                runt = 29;
            if (nm == runmonth)
            {
                cz1 = cz1 + runt;
                if (cz1 > 0)
                {
                    nDay = cz1;
                    YNrun = 1;
                    break;
                }
                else if (cz1 == 0)
                {
                    nm--;
                    i1=c>>(wei1)&~(~0<<1);
                   if (i1 == 1)
                       nDay = 30;
                   else
                       nDay = 29;
                   break;
                }
           }
            cz1 = cz1 + mt;
            if (cz1 > 0)
            {
                nm--;
                nDay = cz1;
                break;
            }
            else if (cz1 == 0)
            {
                nm = nm - 2;
                i1=c>>(wei1+1)&~(~0<<1);
                if( i1 == 1) /*从十二月开始往前逐月取出月的值判断天数,计算月的值*/
                    nDay = 30;
                else
                    nDay=29;     /*计算农历日的值*/
                break;
            }
         nm--;
         wei1++;
        }
   }
    nMonth = nm;

    QDate yin;
    yin.setDate(nYear, nMonth, nDay);
    return yin;
}

QDate MainWindow::conver_from_yin_to_yang(int nyear, int nmonth, int nday)
{
    int gyear, gmonth, gday;
    long int Ndata, c;
    int wei=11, mt, nwhatday=0, runday, runmonth, nm, i, a, whatChunJie, ChunJieYear, zgwhatday, gyday, ms, cz, runt;
    char YNrun = 'n';

     runday = (NongliData[nyear-1899]/0x1000)%0x10;     /*取出判断闰月天数的值*/
     runmonth = (NongliData[nyear-1899]/0x100)%0x10;    /*取出判断是否闰月闰几月的值*/
     if (runday == 1)
         runt = 30;
    else
         runt = 29;

     if (YNrun == 'y')
        nm = nmonth; /*计算该月前面有几个月*/
    else
        nm = nmonth - 1;
       /*计算在该农历年的第几天*/
    Ndata = NongliData[nyear-1899];
    c = Ndata/0x10000;
    wei=11;
    while (wei >= 0 && nm > 0)
    {
        i=c>>wei&~(~0<<1);
        if (i == 1)
            mt = 30;
        else
            mt = 29;
        nwhatday = nwhatday + mt;
        nm--;
        wei--;
    }
    if (nmonth>runmonth && runmonth!=0)
    {
        nwhatday = nwhatday + runt;
    }
    nwhatday = nwhatday + nday;
       /*计算该年春节在公历年的第几天*/
    ChunJieYear = NongliData[nyear-1899];
    a = ChunJieYear%0x100;
    whatChunJie = gPastday[a/100] + a%100;
    if ((ChunJieYear%4==0 && ChunJieYear%100!=0 || ChunJieYear%400==0) && (a/100>2))
        whatChunJie++;
    zgwhatday = nwhatday + whatChunJie - 1;
    /*计算该公历年一年总天数*/
    if (nyear%4==0 && nyear%100!=0 || nyear%400==0)
    {
        gyday=366;
        months[2]=29;
    }
    else
    {
        gyday=365;
        months[2]=28;
    }
     /*换算出公历年份*/
    if (zgwhatday > gyday)
    {
        gyear = nyear + 1;
        zgwhatday = zgwhatday - gyday;
    }
    else
    {
        gyear = nyear;
    }
    /*换算出公历月份*/
    ms = 1;
    cz = zgwhatday;
    gmonth = 0;
    while (ms < 13)
    {
        cz = cz - months[ms];
        if (cz <= 0)
        {
            gmonth++;
            gday = cz + months[ms];
            break;
        }
        gmonth++;
        ms++;
    }

    QDate yang;
    yang.setDate(gyear, gmonth, gday);
    return yang;
}

void MainWindow::show_time(QLabel *label, char flag, int year_hour, int month_minute, int day_second)
{     
    switch (flag)
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

void MainWindow::show_birthday(QLabel *label, char flag, int month, int day)
{
    switch (flag)
    {
    case 'i':  //阴历
    {
        char* yin_month_string[13] = {"零","正月","二月","三月","四月","五月","六月","七月","八月","九月","十月","冬月","腊月"};
        char* yin_day_string[31] = {"零","初一","初二","初三","初四","初五","初六","初七","初八","初九","初十",
                                                               "十一","十二","十三","十四","十五","十六","十七","十八","十九","二十",
                                                               "廿一","廿二","廿三","廿四","廿五","廿六","廿七","廿八","廿九","三十"};
        char* yin_month = yin_month_string[month];
        char* yin_day = yin_day_string[day];
        label->setText(tr("农历%1%2").arg(yin_month).arg(yin_day));
        break;
    }
    case 'a':  //阳历
        label->setText(tr("%1月%2日").arg(month).arg(day));
        break;
    default:
        break;
    }
}
