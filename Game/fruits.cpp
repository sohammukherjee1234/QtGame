#include "fruits.h"
#include<stdlib.h>
#include<string>
#include<cstring>
#include<QTimer>
#include<QGraphicsScene>

 fruits::fruits(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
     srand(time(NULL));
     int xcoord=rand()%30+1;
     int ycoord=rand()%20+1;
     int type=rand()%6+1;


     xcoord*=20;
     ycoord*=20;

     while(xcoord>=800 || ycoord>=600)
     {
          xcoord=rand()%30+1;
          ycoord=rand()%20+1;



         xcoord*=20;
         ycoord*=20;
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
   else if(type==6)
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

