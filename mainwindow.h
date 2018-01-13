#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_quit_triggered();

    void on_settime_triggered();

    void on_rfresh_triggered();

    void on_about_triggered();

    void on_help_triggered();

private:
    Ui::MainWindow *ui;

    int now_year;
    int now_month;
    int now_day;
    int now_hour;
    int now_minute;

    int back_year;
    int back_month;
    int back_day;
    int back_hour;
    int back_minute;
};

#endif // MAINWINDOW_H
