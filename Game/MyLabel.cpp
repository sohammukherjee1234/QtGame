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
#include "utility.h"
#include "bullets.h"
#include "enemy.h"

extern game *newgame;
MyLabel::MyLabel(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    currpower=0;

    startx=utility::framewidth/2;
    starty=utility::frameheight/2;

    //scene()->addText(QString("Score: "+QString::number(currpower)),QFont("times",16));

    setPixmap(QPixmap("/home/soham/Game/images/dog_down.png"));
    QTimer *timer=new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(drawfruit()));
   timer->start(2000);

QTimer *timer2=new QTimer(this);
connect(timer2,SIGNAL(timeout()),this,SLOT(drawenemy()));
timer2->start(2000);

}

void MyLabel::drawfruit()
{
        fruits *fruit=new fruits();
        scene()->addItem(fruit);











}


void MyLabel::drawenemy()
{
    enemy *myenemy=new enemy();
    scene()->addItem(myenemy);
}


void MyLabel::keyPressEvent(QKeyEvent *keyevent)
{
    if(keyevent->key()==Qt::Key_D)
    {


        setPos(x()+utility::charactersize,y());
        setPixmap(QPixmap("/home/soham/Game/images/dog_right.png"));

    }
    else if(keyevent->key()==Qt::Key_W)
    {
        setPos(x(),y()-utility::charactersize);
        setPixmap(QPixmap("/home/soham/Game/images/dog_up.png"));
    }
    else if(keyevent->key()==Qt::Key_A)
    {
        setPos(x()-utility::charactersize,y());
        setPixmap(QPixmap("/home/soham/Game/images/dog_left.png"));
    }
    else if(keyevent->key()==Qt::Key_S)
    {
        setPos(x(),y()+utility::charactersize);
        setPixmap(QPixmap("/home/soham/Game/images/dog_down.png"));
    }

    else if(keyevent->key()==Qt::Key_Up && currpower>0)
    {
        setPixmap(QPixmap("/home/soham/Game/images/dog_up.png"));
        bullets *newbullet=new bullets();
        currpower-=1;
        newbullet->adddirection(1);
        scene()->addItem(newbullet);
    }
    else if(keyevent->key()==Qt::Key_Down && currpower>0)
    {
        setPixmap(QPixmap("/home/soham/Game/images/dog_down.png"));
        bullets *newbullet=new bullets();
        currpower-=1;
        newbullet->adddirection(2);
        scene()->addItem(newbullet);
    }
    else if(keyevent->key()==Qt::Key_Left && currpower>0)
    {
         setPixmap(QPixmap("/home/soham/Game/images/dog_left.png"));
        bullets *newbullet=new bullets();
        currpower-=1;
        newbullet->adddirection(3);
        scene()->addItem(newbullet);
    }
    else if(keyevent->key()==Qt::Key_Right && currpower>0)
    {
        setPixmap(QPixmap("/home/soham/Game/images/dog_right.png"));
        bullets *newbullet=new bullets();
        currpower-=1;
        newbullet->adddirection(4);
        scene()->addItem(newbullet);
    }


    QList<QGraphicsItem *>collidingitem=collidingItems();

    for(int i=0,n=collidingitem.size();i<n;i++)
    {
        if(typeid(*collidingitem[i])==typeid(enemy))
           {

                   scene()->setBackgroundBrush(QPixmap("/home/soham/Game/images/gameover.jpg").scaled(QSize(utility::framewidth,utility::frameheight)));
                   scene()->removeItem(this);
                   delete this;

           }

        if(typeid(*collidingitem[i])==typeid(fruits))
        {
            currpower+=1;  //Score when hit with a fruit
               newgame->mypower->update(currpower);
            scene()->removeItem(collidingitem[i]);
            delete collidingitem[i];
        }



    }


}
