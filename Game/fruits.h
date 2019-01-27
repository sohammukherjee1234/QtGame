#ifndef FRUITS_H
#define FRUITS_H


#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>

#include<QPoint>
#include<stdlib.h>


class fruits:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
    public:
    fruits(QGraphicsItem *parent=0);

public slots:
    void draw();
};


#endif // FRUITS_H

