#include"back.h"
#include<QPixmap>
void BackGround::show(QPainter *p){
    QPixmap pic(":/pic/map.jpg");
    p->drawPixmap(0,0,600,600,pic);
}
BackGround::BackGround(const QPixmap &pix):map(pix){}
