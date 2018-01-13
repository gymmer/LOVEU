#ifndef SETTIME_H
#define SETTIME_H

#include <QDialog>

namespace Ui {
class settime;
}

class settime : public QDialog
{
    Q_OBJECT

public:
    explicit settime(QWidget *parent = 0);
    ~settime();

private slots:
    void on_save_pushButton_clicked();

    void on_cancle_pushButton_clicked();

private:
    Ui::settime *ui;
};

#endif // SETTIME_H
