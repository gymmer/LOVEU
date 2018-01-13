#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu *menu = new QMenu(this);
    menu->addAction(ui->rfreshtime);
    menu->addAction(ui->rfreshmemory);
    menu->addAction(ui->rfreshbirthday);
    menu->addAction(ui->rfreshweather);
    menu->addAction(ui->rfreshword);
    menu->addSeparator();
    menu->addAction(ui->settime);
    menu->addAction(ui->setmemory);
    menu->addAction(ui->setbirthday);
    menu->addAction(ui->setweather);
    menu->addAction(ui->setword);
    menu->addAction(ui->selectword);
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
        time_mode   = 0;

    }
    else    //读取配置文件成功
    {
        QTextStream in(&file);
        back_year   = in.readLine().toInt();
        back_month  = in.readLine().toInt();
        back_day    = in.readLine().toInt();
        back_hour   = in.readLine().toInt();
        back_minute = in.readLine().toInt();
        time_mode   = in.readLine().toInt();
        file.close();
    }
}

void MainWindow::value_memory()
{
    //纪念日。读取配置文件得到
    QFile file("memory.txt");
    if (!file.open(QIODevice::ReadOnly | QFile::Text))  //无配置文件
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
        QTextStream in(&file);
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
        file.close();
    }
}

void MainWindow::value_birthday()
{
    QFile file("birthday.txt");
    if (!file.open(QIODevice::ReadOnly | QFile::Text))  //无配置文件
    {
        QDate current_date = QDate::currentDate();
        my_birthday_month  = current_date.month();
        my_birthday_day    = current_date.day();
        her_birthday_month = current_date.month();
        her_birthday_day   = current_date.day();
        birthday_mode      = 1;

    }
    else    //读取配置文件成功
    {
        QTextStream in(&file);
        my_birthday_month  = in.readLine().toInt();
        my_birthday_day    = in.readLine().toInt();
        her_birthday_month = in.readLine().toInt();
        her_birthday_day   = in.readLine().toInt();
        birthday_mode      = in.readLine().toInt();
        file.close();
    }
}

void MainWindow::value_weather()
{
    QFile file("weather.txt");
    if (!file.open(QIODevice::ReadOnly | QFile::Text))  //无配置文件
    {
        my_city  = "北京";
        her_city = "北京";

    }
    else    //读取配置文件成功
    {
        QTextStream in(&file);
        my_city  = in.readLine();
        her_city = in.readLine();
        file.close();
    }
}

void MainWindow::value_word()
{
    QFile file("wordFileName.txt");
    if (!file.open(QIODevice::ReadOnly | QFile::Text))  //无配置文件
    {
        word_fileName = "\0";
        word_str = "\0";
    }
    else    //读取配置文件成功
    {
        QTextStream in(&file);
        word_fileName = in.readLine();
        word_str = XorDecrypt(word_fileName,11);
        file.close();
    }
}

void MainWindow::refresh_time()
{
    int day_num = day_num_between_days(now_year, now_month, now_day, back_year, back_month, back_day);

    switch (time_mode)
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

void MainWindow::refresh_birthday()
{
    switch (birthday_mode)
    {
    case 0:
        {
        int today_yang_year  = QDate::currentDate().year();
        int today_yang_month = QDate::currentDate().month();
        int today_yang_day   = QDate::currentDate().day();
        QDate today_yin = conver_from_yang_to_yin(today_yang_year, today_yang_month, today_yang_day );

        int my_birthday_yin_month  = my_birthday_month;
        int my_birthday_yin_day    = my_birthday_day;
        int her_birthday_yin_month = her_birthday_month;
        int her_birthday_yin_day   = her_birthday_day;

        int my_nextbirthday_yin_year;
        int her_nextbirthday_yin_year;

        if ( today_yin.month() < my_birthday_yin_month )
        {
            my_nextbirthday_yin_year = today_yin.year();
        }
        else if (today_yin.month() > my_birthday_yin_month)
        {
            my_nextbirthday_yin_year = today_yin.year() + 1;
        }
        else  // today_yin.month() = my_birthday_yin_month
        {
            if (today_yin.day() <= my_birthday_yin_day)
            {
                my_nextbirthday_yin_year = today_yin.year();
            }
            else
            {
                my_nextbirthday_yin_year = today_yin.year() + 1;
            }
        }

        if ( today_yin.month() < her_birthday_yin_month )
        {
            her_nextbirthday_yin_year = today_yin.year();
        }
        else if (today_yin.month() > her_birthday_yin_month)
        {
            her_nextbirthday_yin_year = today_yin.year() + 1;
        }
        else  // today_yin.month() = her_birthday_yin_month
        {
            if (today_yin.day() <= her_birthday_yin_day)
            {
                her_nextbirthday_yin_year = today_yin.year();
            }
            else
            {
                her_nextbirthday_yin_year = today_yin.year() + 1;
            }
        }

        QDate my_next_birthday_yang  = conver_from_yin_to_yang(my_nextbirthday_yin_year,  my_birthday_yin_month,  my_birthday_yin_day);
        QDate her_next_birthday_yang = conver_from_yin_to_yang(her_nextbirthday_yin_year, her_birthday_yin_month, her_birthday_yin_day);
        int my_nextbirthday_num  = day_num_between_days(today_yang_year, today_yang_month,  today_yang_day,
                                                       my_next_birthday_yang.year(),  my_next_birthday_yang.month(),  my_next_birthday_yang.day());
        int her_nextbirthday_num = day_num_between_days(today_yang_year, today_yang_month,  today_yang_day,
                                                       her_next_birthday_yang.year(), her_next_birthday_yang.month(), her_next_birthday_yang.day());

        ui->my_nextbirthday_label->setText(tr("%1").arg(my_nextbirthday_num));
        ui->her_nextbirthday_label->setText(tr("%1").arg(her_nextbirthday_num));
        show_birthday(ui->today_label,        'i', today_yin.month(),      today_yin.day());
        show_birthday(ui->my_birthday_label,  'i', my_birthday_yin_month,  my_birthday_yin_day);
        show_birthday(ui->her_birthday_label, 'i', her_birthday_yin_month, her_birthday_yin_day);
        break;
        }
    case 1:
        {
        int today_yang_year  = QDate::currentDate().year();
        int today_yang_month = QDate::currentDate().month();
        int today_yang_day   = QDate::currentDate().day();

        int my_birthday_yang_month  = my_birthday_month;
        int my_birthday_yang_day    = my_birthday_day;
        int her_birthday_yang_month = her_birthday_month;
        int her_birthday_yang_day   = her_birthday_day;

        int my_nextbirthday_yang_year;
        int her_nextbirthday_yang_year;

        if ( today_yang_month< my_birthday_yang_month )
        {
            my_nextbirthday_yang_year = today_yang_year;
        }
        else if (today_yang_month > my_birthday_yang_month)
        {
            my_nextbirthday_yang_year = today_yang_year + 1;
        }
        else  // today_yang_month() = my_birthday_yang_month
        {
            if (today_yang_day <= my_birthday_yang_day)
            {
                my_nextbirthday_yang_year = today_yang_year;
            }
            else
            {
                my_nextbirthday_yang_year = today_yang_year + 1;
            }
        }

        if ( today_yang_month < her_birthday_yang_month )
        {
            her_nextbirthday_yang_year = today_yang_year;
        }
        else if (today_yang_month > her_birthday_yang_month)
        {
            her_nextbirthday_yang_year = today_yang_year + 1;
        }
        else  // today_yang_month() = her_birthday_yang_month
        {
            if (today_yang_day <= her_birthday_yang_day)
            {
                her_nextbirthday_yang_year = today_yang_year;
            }
            else
            {
                her_nextbirthday_yang_year = today_yang_year + 1;
            }
        }

        int my_nextbirthday_num  = day_num_between_days(today_yang_year, today_yang_month, today_yang_day,
                                                       my_nextbirthday_yang_year,  my_birthday_yang_month,  my_birthday_yang_day);
        int her_nextbirthday_num = day_num_between_days(today_yang_year, today_yang_month, today_yang_day,
                                                       her_nextbirthday_yang_year, her_birthday_yang_month, her_birthday_yang_day);

        ui->my_nextbirthday_label->setText(tr("%1").arg(my_nextbirthday_num));
        ui->her_nextbirthday_label->setText(tr("%1").arg(her_nextbirthday_num));
        show_birthday(ui->today_label,        'a', today_yang_month,        today_yang_day);
        show_birthday(ui->my_birthday_label,  'a', my_birthday_yang_month,  my_birthday_yang_day);
        show_birthday(ui->her_birthday_label, 'a', her_birthday_yang_month, her_birthday_yang_day);
        break;
        }
    default:
        break;
    }
}

void MainWindow::refresh_weather()
{
    int person = ui->select_person_comboBox->currentIndex();
    switch (person)
    {
    case 0:
        {
        my_cityManager.getWeatherbyCityName(my_city, std::bind(&MainWindow::show_weather, this, std::placeholders::_1));
        ui->city_label->setText(my_city);
        break;
        }
    case 1:
        {
        her_cityManager.getWeatherbyCityName(her_city, std::bind(&MainWindow::show_weather, this, std::placeholders::_1));
        ui->city_label->setText(her_city);
        break;
        }
    default:
        break;
    }
}

void MainWindow::show_weather(const QStringList &strList)
{
    if (strList.count() < 23)
    {
        return;
    }

    QString strImage(":/new/prefix1/weather/");
    ui->labelImage1->setPixmap(QPixmap(strImage + strList[8]));
    ui->labelImage2->setPixmap(QPixmap(strImage + strList[9]));
    ui->labelTemperature->setText(strList[5]);
    ui->labelWeather->setText(strList[6]);
    ui->labelWind->setText(strList[7]);

    ui->labelImage3->setPixmap(QPixmap(strImage + strList[15]));
    ui->labelImage4->setPixmap(QPixmap(strImage + strList[16]));
    ui->labelTemperature_2->setText(strList[12]);
    ui->labelWeather_2->setText(strList[13]);
    ui->labelWind_2->setText(strList[14]);
    ui->textBrowser->setText(strList[22]);
}

void MainWindow::refresh_word()
{
    QStringList mylist = word_str.split("\n");
    QString prefix = mylist[0];
    if (prefix != "~!@#$%^&*()_+")
    {
        ui->word_label->setText(tr("没有读取到留言 =.=\n\n\n可能的原因有：\n\n1.尚未选择留言的解密文件\n2.所选择的解密文件不是由本软件生成的"));
        return;
    }

    QString word = mylist[1];
    QString isRequired = mylist[2];
    if (isRequired == "0")
    {
        ui->word_label->setText(word);
    }
    else
    {
        int year   = mylist[3].toInt();
        int month  = mylist[4].toInt();
        int day    = mylist[5].toInt();
        int hour   = mylist[6].toInt();
        int minute = mylist[7].toInt();
        QDateTime words;
        QDate word_date;
        QTime word_time;
        word_date.setDate(year, month, day);
        word_time.setHMS(hour,minute,0);
        words.setDate(word_date);
        words.setTime(word_time);

        if (words.operator <=(QDateTime::currentDateTime()))
        {
            ui->word_label->setText(word + tr("\n\n\n此留言已于 %1年%2月%3日 %4时%5分 开启")
                                    .arg(year).arg(month).arg(day).arg(hour).arg(minute));
        }
        else
        {
            ui->word_label->setText(tr("还没有到揭秘留言的时间哦！\n\n\n留言将于 %1年%2月%3日 %4时%5分 准时开启\n\n敬请期待...")
                                    .arg(year).arg(month).arg(day).arg(hour).arg(minute));
        }
    }
}
