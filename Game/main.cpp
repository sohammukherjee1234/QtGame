
#include <QApplication>

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


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  QGraphicsScene *scene=new QGraphicsScene();

    QPixmap bgimage("/home/soham/Game/images/Snowmap.png");
    bgimage=bgimage.scaled(QSize(800,600));
    scene->setBackgroundBrush(bgimage);






   MyLabel *person=new MyLabel();



    person->setPos(400,300);
   scene->addItem(person);
   person->setFlag(QGraphicsItem::ItemIsFocusable);
   person->setFocus();







   QGraphicsView *view=new QGraphicsView(scene);
view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   view->show();


    view->setFixedSize(800,600);
    view->setSceneRect(0,0,800,600);


    return a.exec();
}
