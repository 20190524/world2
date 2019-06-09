#ifndef TOWERPOINT_H
#define TOWERPOINT_H
#include<QPoint>
#include<QPainter>
#include<QSize>
#include<QImage>
class TowerPoint
{
public:
    TowerPoint() {}
    TowerPoint(QPoint pos);
    bool canHaveTower();
    bool containTower(QPoint &pos);
    const QPoint pos();
    void setHaveTower();
//    void DrawTower(QPainter *p);
    void show(QPainter *p);
private:
    QPoint t_pos;
    bool t_have;
    QPixmap t_pix;
};
#endif // TOWERPOINT_H
