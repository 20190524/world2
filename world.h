#ifndef WORLD_H
#define WORLD_H

#include<QPainter>
#include<QMediaPlayer>
#include<QImage>
#include<QPixmap>
#include"soldier.h"
#include"back.h"
#include"waypoint.h"
#include"towerpoint.h"
#include"tower.h"
#include<QList>
//#include"fire.h"
class World
{
public:
    World() {
        this->_s1=new Soldier;
        this->_map=new BackGround(QPixmap(":/pic/map.jpg"));
//        QList<waypoint*> _waypointlist=new QList<waypoint *>;
    }
    ~World();
    void intWorld();
    void show(QPainter *p);
//    void soldierMove(int step);
    void soldierMove();
    void addWaypoint();
    void addTowerPoint();
    QPoint getTowerPosition(int t);
    TowerPoint* getEveryTowerPosition(int e);
//    TowerPoint* getFirstTowerPosition();
    int getTowerNum();
    void setTower(QPoint &tpos);
    bool canPutTower(TowerPoint* tpoint,QPoint &tpos);
//    void fireMove(int step);
private:
    Soldier *_s1,*_s2;
    BackGround *_map;
    QList<waypoint *> _waypointlist;
    QList<TowerPoint*> _towerpointlist;
    QList<Tower*> _towerlist;
//    Fire *_f;
};
#endif // WORLD_H
