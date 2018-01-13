#ifndef USAGE_H
#define USAGE_H

#include <QDialog>

namespace Ui {
class usage;
}

class usage : public QDialog
{
    Q_OBJECT

public:
    explicit usage(QWidget *parent = 0);
    ~usage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::usage *ui;
};

#endif // USAGE_H
