#include "info.h"
#include "ui_info.h"

info::info(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);
    setWindowTitle("关于作者");
}

info::~info()
{
    delete ui;
}

void info::on_pushButton_clicked()
{
    close();
}
