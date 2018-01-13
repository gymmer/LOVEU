#ifndef SETBIRTHDAY_H
#define SETBIRTHDAY_H

#include <QDialog>

namespace Ui {
class setbirthday;
}

class setbirthday : public QDialog
{
    Q_OBJECT

public:
    explicit setbirthday(QWidget *parent = 0);
    ~setbirthday();

private slots:
    void on_save_pushButton_clicked();

    void on_cancel_pushButton_clicked();

private:
    Ui::setbirthday *ui;
};

#endif // SETBIRTHDAY_H
