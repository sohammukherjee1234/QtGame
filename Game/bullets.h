#ifndef BULLETS_H
#define BULLETS_H


#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>
class bullets:public QObject,public QGraphicsPixmapItem
{
   Q_OBJECT
public:
    bullets(QGraphicsPixmapItem *parent=0);

    int startx;
    int starty;
    int dir;

public slots:
    void move();
    void adddirection(int direction);
};


#endif // BULLETS_H
