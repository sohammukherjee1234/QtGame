#include "bullets.h"
#include "game.h"
#include "utility.h"
#include <QTimer>
#include "enemy.h"
extern game *newgame;

bullets::bullets(QGraphicsPixmapItem *parent):QObject(),QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap("/home/soham/Game/images/bullets.png"));
    startx=newgame->person->x();
    starty=newgame->person->y();
    dir=0;
    setPos(startx,starty);
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
}

void bullets::adddirection(int direction){
    dir=direction;
}


void bullets::move()
{

       if(dir==1)
       {
           //up
           setPos(x(),y()-10);

       }
       else if(dir==2)
       {
           //down
           setPos(x(),y()+10);
       }
       else if(dir==3)
       {
           //left
           setPos(x()-10,y());
       }
       else if(dir==4)
       {
           setPos(x()+10,y());
       }



       if(x()>=utility::framewidth || y()>=utility::frameheight){scene()->removeItem(this); delete(this);}

       QList<QGraphicsItem *>collidingitem=collidingItems();

       for(int i=0,n=collidingitem.size();i<n;i++)
       {

           if(typeid(*collidingitem[i])==typeid(enemy))
           {
               scene()->removeItem(collidingitem[i]);
               delete collidingitem[i];
           }
       }
}
