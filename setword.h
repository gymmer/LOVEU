#ifndef SETWORD_H
#define SETWORD_H

#include <QDialog>
#include <QFileDialog>
#include "XorEncryptDecrypt.h"

namespace Ui {
class setword;
}

class setword : public QDialog
{
    Q_OBJECT

public:
    explicit setword(QWidget *parent = 0);
    ~setword();

private slots:
    void on_path_pushButton_clicked();

    void on_save_pushButton_clicked();

    void on_cancel_pushButton_clicked();

    void on_no_radioButton_clicked();

    void on_yes_radioButton_clicked();

private:
    Ui::setword *ui;
};

#endif // SETWORD_H
