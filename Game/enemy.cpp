#include "enemy.h"
#include "utility.h"
#include<stdlib.h>
#include<QTimer>
#include<QGraphicsScene>
#include "game.h"

extern game *newgame;

enemy::enemy(QGraphicsPixmapItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    srand(time(NULL));

    int choice=rand()%2;

    if(choice==0)
    {
        setPixmap(QPixmap("/home/soham/Game/images/down.png"));
        int xcoord=rand()%(utility::framewidth/utility::charactersize)+1;
        xcoord*=utility::charactersize;
        while(xcoord>=utility::framewidth)
        {
         xcoord=rand()%(utility::framewidth/utility::charactersize)+1;

            xcoord*=utility::charactersize;

        }

        setPos(xcoord,0);
        enemydir=0;
    }
    else
    {
        setPixmap(QPixmap("/home/soham/Game/images/right.png"));
        int ycoord=rand()%(utility::frameheight/utility::charactersize)+1;
        ycoord*=utility::charactersize;
        while(ycoord>=utility::frameheight)
        {
         ycoord=rand()%(utility::frameheight/utility::charactersize)+1;

            ycoord*=utility::charactersize;

        }

        setPos(0,ycoord);
        enemydir=2;
    }



  QTimer *timer1=new QTimer(this);
 QTimer *timer2=new QTimer(this);

    connect(timer1,SIGNAL(timeout()),this,SLOT(move()));
    timer1->start(1000);

 connect(timer2,SIGNAL(timeout()),this,SLOT(death()));
timer2->start(10000);

}

void enemy::move()
{
    if(enemydir==0)
    {
        setPixmap(QPixmap("/home/soham/Game/images/down.png"));
        if(y()+utility::charactersize>utility::frameheight)
        {
            enemydir=1;

        }
        else setPos(x(),y()+utility::charactersize);
    }
    else if(enemydir==1)
    {
        setPixmap(QPixmap("/home/soham/Game/images/up.png"));
        if(y()-utility::charactersize<0)
        {
            enemydir=0;

        }
        else setPos(x(),y()-utility::charactersize);
    }
    else if(enemydir==2)
    {
        setPixmap(QPixmap("/home/soham/Game/images/right.png"));
        if(x()+utility::charactersize>utility::framewidth)
        {
            enemydir=3;

        }
        else setPos(x()+utility::charactersize,y());
    }
    else if(enemydir==3)
    {
        setPixmap(QPixmap("/home/soham/Game/images/left.png"));
        if(x()-utility::charactersize<0)
        {
            enemydir=2;

        }
        else setPos(x()-utility::charactersize,y());
    }
}

void enemy::death()
{
    scene()->removeItem(this);
    delete this;
}
