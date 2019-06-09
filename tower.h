#ifndef TOWER_H
#define TOWER_H
#include<QPainter>
#include<QPoint>
#include<QImage>
#include<QPixmap>
class Tower
{
public:
    Tower() {}
    Tower(QPoint &Tpos,const QPixmap&pix=QPixmap(":/pic/tower.png"));
    void show(QPainter *p);
private:
    QPoint T_pos;
//    QImage T_ima;
    QPixmap T_pix;
};
#endif // TOWER_H
