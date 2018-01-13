#include "setweather.h"
#include "ui_setweather.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

setweather::setweather(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setweather)
{
    ui->setupUi(this);
    setWindowTitle("设置");

    my_cityManager.getSupportProvince (std::bind(&setweather::onProvinces, this, std::placeholders::_1));
    her_cityManager.getSupportProvince(std::bind(&setweather::onProvinces, this, std::placeholders::_1));
}

void setweather::onProvinces(const QStringList &strList)
{
    QStringList::const_iterator citer = strList.constBegin();
    for ( ; citer != strList.constEnd(); ++citer)
    {
        ui->my_province_comboBox->addItem(*citer);
        ui->her_province_comboBox->addItem(*citer);
    }
    my_cityManager.getSupportCity (ui->my_province_comboBox->currentText(),  std::bind(&setweather::onMyCitys,  this, std::placeholders::_1));
    her_cityManager.getSupportCity(ui->her_province_comboBox->currentText(), std::bind(&setweather::onHerCitys, this, std::placeholders::_1));
}

void setweather::onMyCitys(const QStringList &strList)
{
    ui->my_city_comboBox->clear();
    QStringList::const_iterator citer = strList.constBegin();
    for ( ; citer != strList.constEnd(); ++citer)
    {
        QString str = citer->left(citer->indexOf(QChar(' ')));
        ui->my_city_comboBox->addItem(str);
    }
}

void setweather::onHerCitys(const QStringList &strList)
{
    ui->her_city_comboBox->clear();
    QStringList::const_iterator citer = strList.constBegin();
    for ( ; citer != strList.constEnd(); ++citer)
    {
        QString str = citer->left(citer->indexOf(QChar(' ')));
        ui->her_city_comboBox->addItem(str);
    }
}

setweather::~setweather()
{
    delete ui;
}

void setweather::on_save_pushButton_clicked()
{
    QString my_city      = ui->my_city_comboBox->currentText();
    QString her_city     = ui->her_city_comboBox->currentText();

    //以只写方式打开文件。若文件不存在，那么创建文件weather.txt
    QFile file("weather.txt");
    if (!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        qDebug() << endl << file.errorString();
    }
    QTextStream out(&file);
    out << my_city << endl << her_city;
    file.close();
    close();
}

void setweather::on_cancel_pushButton_clicked()
{
    close();
}

void setweather::on_my_province_comboBox_currentIndexChanged(const QString &my_provinceName)
{
    my_cityManager.getSupportCity(my_provinceName, std::bind(&setweather::onMyCitys, this, std::placeholders::_1));
}

void setweather::on_her_province_comboBox_currentIndexChanged(const QString &her_provinceName)
{
    her_cityManager.getSupportCity(her_provinceName, std::bind(&setweather::onHerCitys, this, std::placeholders::_1));
}

