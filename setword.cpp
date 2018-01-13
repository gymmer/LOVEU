#include "setword.h"
#include "ui_setword.h"

setword::setword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setword)
{
    ui->setupUi(this);
    setWindowTitle("设置");
    ui->yes_radioButton->setChecked(false);
    ui->no_radioButton->setChecked(true);
    ui->dateTimeEdit->setEnabled(false);
    QDateTime current = QDateTime::currentDateTime();
    ui->dateTimeEdit->setMinimumDateTime(current);
}

setword::~setword()
{
    delete ui;
}

void setword::on_path_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "选择路径");
    ui->path_lineEdit->setText(fileName);
}

void setword::on_save_pushButton_clicked()
{
    QString fileName = ui->path_lineEdit->text();
    QString str;

    QString prefix = "~!@#$%^&*()_+";
    QString word = ui->lineEdit->text();
    if (ui->no_radioButton->isChecked())
    {
        QString isRequired = "0";
        str = prefix + '\n' + word + '\n' + isRequired;
    }
    else if (ui->yes_radioButton->isChecked())
    {
        QString isRequired = "1";
        int year   = ui->dateTimeEdit->date().year();
        int month  = ui->dateTimeEdit->date().month();
        int day    = ui->dateTimeEdit->date().day();
        int hour   = ui->dateTimeEdit->time().hour();
        int minute = ui->dateTimeEdit->time().minute();

        str = prefix + '\n' + word + '\n' + isRequired + '\n' +
              QString::number(year) + '\n' + QString::number(month) + '\n' + QString::number(day) + '\n' +
              QString::number(hour) + '\n' + QString::number(minute) ;
    }

    XorEncrypt(fileName,str,11);
    close();
}

void setword::on_cancel_pushButton_clicked()
{
    close();
}

void setword::on_no_radioButton_clicked()
{
    ui->dateTimeEdit->setEnabled(false);
}

void setword::on_yes_radioButton_clicked()
{
    ui->dateTimeEdit->setEnabled(true);
}
