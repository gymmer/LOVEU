#include "usage.h"
#include "ui_usage.h"

usage::usage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::usage)
{
    ui->setupUi(this);
    setWindowTitle("使用方法");
}

usage::~usage()
{
    delete ui;
}

void usage::on_pushButton_clicked()
{
    close();
}
