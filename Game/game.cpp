#include "game.h"
#include<QPoint>
#include<QPainter>
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QGraphicsView>
#include "MyLabel.h"
#include<QPixmap>
#include<QGraphicsRectItem>
#include<stdlib.h>
#include<QPixmap>
#include "MyLabel.h"
#include "utility.h"

game::game(QGraphicsView *parent):QGraphicsView(parent)
{
    scene=new QGraphicsScene();
    person=new MyLabel();
    mypower=new power();

}

void game::show()
{
    QPixmap bgimage("/home/soham/Game/images/Snowmap.png");
    bgimage=bgimage.scaled(QSize(utility::framewidth,utility::frameheight));
    scene->setBackgroundBrush(bgimage);

    person->setPos(utility::framewidth/2,utility::frameheight/2);
   scene->addItem(person);
   person->setFlag(QGraphicsItem::ItemIsFocusable);
   person->setFocus();

   mypower->setPos(20,20);

   scene->addItem(mypower);


   QGraphicsView *view=new QGraphicsView(scene);
view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   view->show();


    view->setFixedSize(utility::framewidth,utility::frameheight);
    view->setSceneRect(0,0,utility::framewidth,utility::frameheight);
}
