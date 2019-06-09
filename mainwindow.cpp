#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTime>
#include<QTimer>
#include<QMouseEvent>
#include<QPixmap>
#include <QMediaPlayer>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Qt::WindowFlags flags=0;
    flags=Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    setFixedSize(600,600);

    _game.intWorld();

    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(soldierMove()));
    timer->start(50);
    timer->setInterval(500);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event){
    if(_pagesign==true){
        QPainter p(this);
        p.drawPixmap(0,0,600,600,QPixmap(":/pic/mainpage.jpg"));
    }
    if(_sign==true){
        QPainter *p1;
        p1=new QPainter();
        p1->begin(this);
        this->_game.show(p1);
        p1->end();
        delete p1;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    _click=event->pos();
    if(event->button()==Qt::LeftButton&&_click.rx()<=380&&_click.rx()>=220&&_click.ry()<=330&&_click.ry()>=270){
        _sign=true;
        _pagesign=false;
    }
    if(_sign&&!_pagesign){
        if(event->button()==Qt::LeftButton){
            for(int i=0;i<_game.getTowerNum();i++){
                TowerPoint*t=_game.getEveryTowerPosition(i);
                if(_game.canPutTower(t,_click)){
                    _game.setTower(_click);
                    update();
                    break;
                }
            }
            /*auto it=_game.getFirstTowerPosition();
            while (it!=_game.getLastTowerPosition()) {
                if(_game.canPutTower(it,_click)){
                    _game.setTower(_click);
                    update();
                    break;
                }
                ++it;
            }*/
        }

    }
}
void MainWindow::soldierMove(){
    if(_sign==true){
        this->_game.soldierMove();
        this->repaint();
        QMediaPlayer * player = new QMediaPlayer;
        player->setMedia(QUrl("qrc:/sound/ice.mp3"));
        player->setVolume(30);
        player->play();

    }
//    update();

}
