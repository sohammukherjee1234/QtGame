#ifndef GAME_H
#define GAME_H

#include<QGraphicsView>
#include<QGraphicsScene>
#include "MyLabel.h"
#include "power.h"
#include "utility.h"
class game: public QGraphicsView
{
public:
       game(QGraphicsView *parent=0);

       QGraphicsScene *scene;
       MyLabel *person;
       power *mypower;
public slots:
       void show();

};

#endif // GAME_H
