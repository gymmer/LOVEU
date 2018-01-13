#ifndef SETMEMORY_H
#define SETMEMORY_H

#include <QDialog>

namespace Ui {
class setmemory;
}

class setmemory : public QDialog
{
    Q_OBJECT

public:
    explicit setmemory(QWidget *parent = 0);
    ~setmemory();

private slots:
    void on_save_pushButton_clicked();

    void on_cancel_pushButton_clicked();

private:
    Ui::setmemory *ui;
};

#endif // SETMEMORY_H
