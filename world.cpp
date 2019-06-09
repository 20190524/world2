#include"world.h"
#include"soldier.h"
#include"back.h"
#include<QMediaPlayer>
#include<QPoint>
#include"tower.h"
//#include"fire.h"
void World::show(QPainter *p){
//    QPixmap pic(":/pic/map.jpg");
    this->_map->show(p);
    for(int j=0;j<_towerpointlist.size();j++){
        this->_towerpointlist[j]->show(p);
    }
    int i;
    for(i=0;i<_waypointlist.size();i++){
        this->_waypointlist[i]->draw(p);
    }
    this->_s1->show(p);
    this->_s2->show(p);
    foreach (Tower*tower, _towerlist) {
        tower->show(p);
    }
//    this->_f->show(p);
}
//void World::soldierMove(int step){
void World::soldierMove(){
//    this->_s->move(step);
    this->_s1->move();
    this->_s2->move();

}


/*void World::fireMove(int step){
    this->_f->move(step);
}*/


World::~World(){
    delete this->_s1;
    delete this->_s2;
    delete this->_map;
    int i;
    for(i=0;i<_waypointlist.size();i++){
        delete this->_waypointlist[i];
    }
    int j;
    for(j=0;j<_towerpointlist.size();j++){
        delete this->_towerpointlist[j];
    }
//    delete this->_f;
}
void World::intWorld(){
    addWaypoint();
    addTowerPoint();
    waypoint*startpoint1=_waypointlist[5];
    waypoint*startpoint2=_waypointlist[11];
    QPixmap pic(":/pic/map.jpg");
    _s1=new Soldier(startpoint1);
    _s2=new Soldier(startpoint2);
    _map=new BackGround(pic);
//    Soldier(waypoint(QPoint(480,560)));
//    this->_s->setPosX(480);
//    this->_s->setPosY(560);

}

void World::addWaypoint(){
    waypoint *waypoint1=new waypoint(QPoint(30,200));
    _waypointlist.push_back(waypoint1);

    waypoint *waypoint2=new waypoint(QPoint(140,270));
    _waypointlist.push_back(waypoint2);
    waypoint2->setNextWayPoint(waypoint1);

    waypoint *waypoint3=new waypoint(QPoint(110,400));
    _waypointlist.push_back(waypoint3);
    waypoint3->setNextWayPoint(waypoint2);

    waypoint *waypoint4=new waypoint(QPoint(160,500));
    _waypointlist.push_back(waypoint4);
    waypoint4->setNextWayPoint(waypoint3);

    waypoint *waypoint5=new waypoint(QPoint(420,440));
    _waypointlist.push_back(waypoint5);
    waypoint5->setNextWayPoint(waypoint4);

    waypoint *waypoint6=new waypoint(QPoint(480,560));
    _waypointlist.push_back(waypoint6);
    waypoint6->setNextWayPoint(waypoint5);

    waypoint *waypoint7=new waypoint(QPoint(190,270));
    _waypointlist.push_back(waypoint7);
    waypoint7->setNextWayPoint(waypoint2);

    waypoint *waypoint8=new waypoint(QPoint(240,200));
    _waypointlist.push_back(waypoint8);
    waypoint8->setNextWayPoint(waypoint7);

    waypoint *waypoint9=new waypoint(QPoint(340,170));
    _waypointlist.push_back(waypoint9);
    waypoint9->setNextWayPoint(waypoint8);

    waypoint *waypoint10=new waypoint(QPoint(390,250));
    _waypointlist.push_back(waypoint10);
    waypoint10->setNextWayPoint(waypoint9);

    waypoint *waypoint11=new waypoint(QPoint(490,220));
    _waypointlist.push_back(waypoint11);
    waypoint11->setNextWayPoint(waypoint10);

    waypoint *waypoint12=new waypoint(QPoint(510,120));
    _waypointlist.push_back(waypoint12);
    waypoint12->setNextWayPoint(waypoint11);
}

void World::addTowerPoint(){
    TowerPoint *towerpoint1=new TowerPoint(QPoint(380,520));
    _towerpointlist.push_back(towerpoint1);

    TowerPoint *towerpoint2=new TowerPoint(QPoint(180,380));
    _towerpointlist.push_back(towerpoint2);

    TowerPoint *towerpoint3=new TowerPoint(QPoint(170,160));
    _towerpointlist.push_back(towerpoint3);

    TowerPoint *towerpoint4=new TowerPoint(QPoint(45,300));
    _towerpointlist.push_back(towerpoint4);

    TowerPoint *towerpoint5=new TowerPoint(QPoint(305,215));
    _towerpointlist.push_back(towerpoint5);

    TowerPoint *towerpoint6=new TowerPoint(QPoint(420,150));
    _towerpointlist.push_back(towerpoint6);
}

QPoint World::getTowerPosition(int t){
    return _towerpointlist[t]->pos();
}

int World::getTowerNum(){
    return _towerpointlist.size();
}

void World::setTower(QPoint &tpos){
//    QImage tima(":/pic/tower.png");
    QPixmap tpix(":/pic/tower.png");
    Tower*t=new Tower(tpos,tpix);
    _towerlist.push_back(t);
}

bool World::canPutTower(TowerPoint *tpoint, QPoint &tpos){
    bool judge=tpoint->containTower(tpos)&&!tpoint->canHaveTower();
    if(judge)tpoint->setHaveTower();
    return judge;
}

TowerPoint* World::getEveryTowerPosition(int e){
    return _towerpointlist[e];
}

//TowerPoint* World::getFirstTowerPosition(){
//    return _towerpointlist.begin();
//}
