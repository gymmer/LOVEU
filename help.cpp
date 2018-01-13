#include "help.h"
#include "ui_help.h"

help::help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);
    setWindowTitle("使用方法");
}

help::~help()
{
    delete ui;
}

void help::on_pushButton_clicked()
{
    close();
}
