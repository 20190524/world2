#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include"soldier.h"
#include"world.h"
#include<QTime>
#include<QTimer>
#include<QPoint>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

protected slots:
    void soldierMove();

private:
    Ui::MainWindow *ui;
    World _game;
    QTimer *timer;
    QPoint _click;
    bool _sign=false;
    bool _pagesign=true;
    bool _cantower;
};

#endif // MAINWINDOW_H
