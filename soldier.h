
#ifndef SOLDIER_H
#define SOLDIER_H
#include<QPainter>
#include<QImage>
#include <QMediaPlayer>
#include<QPoint>
#include"waypoint.h"

class Soldier
{
public:
    Soldier() {}
    Soldier(waypoint *startpoint);
    void show(QPainter *p);
//    void move(int step);
    void move();
    int getNextX();
    int getNextY();
    void setPosX(double x){this->s_pos.rx()=x;}
    void setPosY(double y){this->s_pos.ry()=y;}
//    void onMove();
private:

    int s_speed=5;
    double s_rotationSpirite;
    bool _movable;
    bool _mywin;
    waypoint *s_despoint;
    QPoint s_pos;

//    int _pos_x,_pos_y;
//    QImage s_ima;
//    QImage _sp;
};

#endif // SOLDIER_H
