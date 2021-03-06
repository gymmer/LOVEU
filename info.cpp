#include "info.h"
#include "ui_info.h"

info::info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);
    setWindowTitle("关于作者");

    ui->version_label->setText("版本：5.0");
    ui->date_label->setText("日期：2015.2.4");
}

info::~info()
{
    delete ui;
}

void info::on_pushButton_clicked()
{
    close();
}
