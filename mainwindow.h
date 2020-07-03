#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "view.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ButtonDisplay_Pushed();


private:
    Ui::MainWindow *ui;
    QPushButton* button_display;
    QPushButton* button_magnification_up;
    QPushButton* button_magnification_down;
    QPushButton* button_magnification_reset;

    View* view_;
    QTimer* timer;
    void onTimer();
    int i=0;
};
#endif // MAINWINDOW_H
