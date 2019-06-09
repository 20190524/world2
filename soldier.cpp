#include"soldier.h"
#include<cmath>
#include <QMediaPlayer>
#include"strike.h"
#include<QVector2D>
Soldier::Soldier(waypoint *startpoint)
    :s_despoint(startpoint->nextWayPoint())
    ,s_pos(startpoint->pos())
    ,s_speed(4)
    ,s_rotationSpirite(0.0)
    ,_mywin(false){

}

//void Soldier::move(int step){
void Soldier::move(){
//    this->s_pos.rx()-=step;
//    if(2*(s_pos.rx()/2)==s_pos.rx())this->s_pos.ry()+=step;
//    else s_pos.ry()-=step;


    if(collisionWithCircle(s_pos,3,s_despoint->pos(),3)){
        if(s_despoint->nextWayPoint()){
            s_pos=s_despoint->pos();
            s_despoint=s_despoint->nextWayPoint();
        }
        else{
            _mywin=true;
            return;
        }
    }

    QPoint targetPoint = s_despoint->pos();

    qreal movementSpeed = s_speed;
    QVector2D normalized(targetPoint - s_pos);
    normalized.normalize();
    s_pos = s_pos + normalized.toPoint() * movementSpeed;
    s_rotationSpirite=qRadiansToDegrees(qAtan2(normalized.y(),normalized.x()))+180;
}
void Soldier::show(QPainter *p){
    QImage ima(":/pic/soldier.png");
//    this->_sp=ima.copy(QRect(150,80,120,70));
    p->drawImage(s_pos.rx(),s_pos.ry(),ima,150,80,120,70);//
//    p->drawImage(_pos_x,_pos_y,ima,150,80,120,70);
//    p->drawImage(this->_pos_x,this->_pos_y,this->_sp);
}



//int Soldier::getNextX(){
//    return this->s_pos.rx()-1;
//}
//int Soldier::getNextY(){
//    return this->s_pos.ry();
//}
