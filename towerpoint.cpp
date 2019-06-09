#include"towerpoint.h"

TowerPoint::TowerPoint(QPoint pos):t_pos(pos)
  ,t_have(false){

}

void TowerPoint::show(QPainter *p){
    p->save();
    p->setBrush(Qt::NoBrush);
    p->drawEllipse(t_pos,6,6);
    p->drawEllipse(t_pos,2,2);
    p->restore();
}

const QPoint TowerPoint::pos(){
    return t_pos;
}

bool TowerPoint::containTower(QPoint &pos){
    bool X=((pos.rx()<(t_pos.rx()+15))&&(pos.rx()>(t_pos.rx()-15)));
    bool Y=((pos.ry()<(t_pos.ry()+15))&&(pos.ry()>(t_pos.ry()-15)));
    return X&&Y;
}

bool TowerPoint::canHaveTower(){
    return t_have;
}

/*void TowerPoint::DrawTower(QPainter *p){
    p->drawImage(t_pos.rx(),t_pos.ry(),t_pix,0,0,200,200);
}*/

void TowerPoint::setHaveTower(){
    t_have=true;
}
