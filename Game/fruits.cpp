#include "fruits.h"
#include<stdlib.h>
#include<string>
#include<cstring>
#include<QTimer>
#include<QGraphicsScene>
#include "utility.h"
 fruits::fruits(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
     srand(time(NULL));
     int xcoord=rand()%(utility::framewidth/utility::charactersize)+1;
     int ycoord=rand()%(utility::frameheight/utility::charactersize)+1;
     int type=rand()%6+1;


     xcoord*=utility::charactersize;
     ycoord*=utility::charactersize;

     while(xcoord>=utility::framewidth || ycoord>=utility::frameheight)
     {
        xcoord=rand()%(utility::framewidth/utility::charactersize)+1;
         ycoord=rand()%(utility::frameheight/utility::charactersize)+1;



         xcoord*=utility::charactersize;
         ycoord*=utility::charactersize;
     }

     setPos(xcoord,ycoord);


    if(type==1)
    setPixmap(QPixmap("/home/soham/Game/images/fruits/1.png"));

    else if(type==2)
    setPixmap(QPixmap("/home/soham/Game/images/fruits/2.png"));
    else if(type==3)
    setPixmap(QPixmap("/home/soham/Game/images/fruits/3.png"));
    else if(type==4)
    setPixmap(QPixmap("/home/soham/Game/images/fruits/4.png"));
    else if(type==5)
    setPixmap(QPixmap("/home/soham/Game/images/fruits/5.png"));
    else
    setPixmap(QPixmap("/home/soham/Game/images/fruits/6.png"));

    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(draw()));
    timer->start(10000);
}
\

 void fruits::draw(){


     scene()->removeItem(this);

     delete this;
 }

