#include "setbirthday.h"
#include "ui_setbirthday.h"
#include <QDate>
#include <QFile>
#include <QTextStream>
#include <QDebug>

setbirthday::setbirthday(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setbirthday)
{
    ui->setupUi(this);
    setWindowTitle("设置");

    ui->my_birthday_dateEdit->setDisplayFormat("MM-dd");
    ui->her_birthday_dateEdit->setDisplayFormat("MM-dd");

    QDate current_date = QDate::currentDate();
    QDate my_birthday;
    QDate her_birthday;
    int birthday_mode;

    //以只读方式打开配置文件birthday.txt
    QFile file("birthday.txt");
    if (!file.open(QIODevice::ReadOnly | QFile::Text))  //无配置文件，显示当前时间
    {
        int current_year   = current_date.year();
        int current_month  = current_date.month();
        int current_day    = current_date.day();

        my_birthday.setDate(current_year, current_month, current_day);
        her_birthday.setDate(current_year, current_month, current_day);
    }
    else    //读取配置文件成功
    {
        QTextStream in(&file);
        int my_birthday_month  = in.readLine().toInt();
        int my_birthday_day = in.readLine().toInt();
        int her_birthday_month   = in.readLine().toInt();
        int her_birthday_day  = in.readLine().toInt();
        birthday_mode = in.readLine().toInt();

        my_birthday.setDate(1900,my_birthday_month, my_birthday_day);
        her_birthday.setDate(1900,her_birthday_month, her_birthday_day);

        file.close();
    }

    ui->my_birthday_dateEdit->setDate(my_birthday);
    ui->her_birthday_dateEdit->setDate(her_birthday);
    ui->birthday_mode_comboBox->setCurrentIndex(birthday_mode);
}

setbirthday::~setbirthday()
{
    delete ui;
}

void setbirthday::on_save_pushButton_clicked()
{
    QDate my_birthday = ui->my_birthday_dateEdit->date();
    QDate her_birthday = ui->her_birthday_dateEdit->date();
    int mode  = ui->birthday_mode_comboBox->currentIndex();

    //以只写方式打开文件。若文件不存在，那么创建文件birthday.txt
    QFile file("birthday.txt");
    if (!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        qDebug() << endl << file.errorString();
    }
    QTextStream out(&file);
    out << my_birthday.month() << endl << my_birthday.day() << endl
          << her_birthday.month() << endl << her_birthday.day() << endl << mode;
    file.close();
    close();
}

void setbirthday::on_cancel_pushButton_clicked()
{
    close();
}
