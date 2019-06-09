#ifndef BACK_H
#define BACK_H
#include<QPainter>
#include<QPixmap>
class BackGround
{
public:
    BackGround() {}
    BackGround(const QPixmap &pix=QPixmap(":/pic/map.jpg"));
    void show(QPainter*p);
private:
    QPixmap map;
};

#endif // BACK_H
