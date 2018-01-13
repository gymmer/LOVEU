#ifndef SETWEATHER_H
#define SETWEATHER_H

#include <QDialog>
#include "citymanager.h"

namespace Ui {
class setweather;
}

class QNetworkAccessManager;
class QNetworkReply;

class setweather : public QDialog
{
    Q_OBJECT

public:
    explicit setweather(QWidget *parent = 0);
    ~setweather();

    void onProvinces(const QStringList &strList);
    void onMyCitys(const QStringList &strList);
    void onHerCitys(const QStringList &strList);

private slots:
    void on_save_pushButton_clicked();
    void on_cancel_pushButton_clicked();
    void on_my_province_comboBox_currentIndexChanged(const QString &my_provinceName);
    void on_her_province_comboBox_currentIndexChanged(const QString &her_provinceName);

private:
    Ui::setweather *ui;
    CityManager my_cityManager;
    CityManager her_cityManager;
};

#endif // SETWEATHER_H
