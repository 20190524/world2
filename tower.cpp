#include"tower.h"
Tower::Tower(QPoint &Tpos,const QPixmap&pix):T_pos(Tpos)
  ,T_pix(pix){

}

void Tower::show(QPainter *p){
    QPixmap pix(":/pic/tower.png");
    p->drawPixmap(T_pos.rx()-10,T_pos.ry()-30,50,50,pix);
}
