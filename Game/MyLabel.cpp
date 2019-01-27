#include "MyLabel.h"
#include<QKeyEvent>
#include<QDebug>
#include<QTimer>
#include<QList>
#include<QGraphicsScene>
#include "fruits.h"
#include<QSize>
#include<algorithm>
#include<QFont>
#include <QString>
#include "game.h"

extern game *newgame;
MyLabel::MyLabel(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    currpower=10000;

    startx=400;
    starty=300;

    //scene()->addText(QString("Score: "+QString::number(currpower)),QFont("times",16));

    setPixmap(QPixmap("/home/soham/Game/images/standing-still.png"));
    QTimer *timer=new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(drawfruit()));
   timer->start(1000);

}

void MyLabel::drawfruit()
{
        fruits *fruit=new fruits();
        scene()->addItem(fruit);

        currpower-=20;

        newgame->mypower->update(currpower);

        if(currpower<=0)
        {
            scene()->setBackgroundBrush(QPixmap("/home/soham/Game/images/gameover.jpg").scaled(QSize(800,600)));
            scene()->removeItem(this);
            delete this;
        }

}



void MyLabel::keyPressEvent(QKeyEvent *keyevent)
{
    if(keyevent->key()==Qt::Key_D)
    {


        setPos(x()+20,y());
    }
    else if(keyevent->key()==Qt::Key_W)
    {
        setPos(x(),y()-20);
    }
    else if(keyevent->key()==Qt::Key_A)
    {
        setPos(x()-20,y());
    }
    else if(keyevent->key()==Qt::Key_S)
    {
        setPos(x(),y()+20);
    }


    QList<QGraphicsItem *>collidingitem=collidingItems();

    for(int i=0,n=collidingitem.size();i<n;i++)
    {
        if(typeid(*collidingitem[i])==typeid(fruits))
        {
            currpower+=1000;  //Score when hit with a fruit

            scene()->removeItem(collidingitem[i]);
            delete collidingitem[i];
        }


    }

    currpower-=(abs(x()-startx))+(abs(y()-starty));
    newgame->mypower->update(currpower);
    if(currpower<=0)
    {
        scene()->setBackgroundBrush(QPixmap("/home/soham/Game/images/gameover.jpg").scaled(QSize(800,600)));
        scene()->removeItem(this);
        delete this;
    }
}
