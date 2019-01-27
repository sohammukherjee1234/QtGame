#ifndef ENEMY_H
#define ENEMY_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QGraphicsItem>
class enemy:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enemy(QGraphicsPixmapItem *parent=0);
    virtual ~enemy(){};
    int enemydir;

public slots:
    void move();
    void death();
};




#endif // ENEMY_H
