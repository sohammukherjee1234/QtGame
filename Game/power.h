#ifndef POWER_H
#define POWER_H


#include <QGraphicsTextItem>
#include "utility.h"
class power:public QGraphicsTextItem
{
public:
    power(QGraphicsTextItem *parent=0);

    int score;

public slots:
    void update(int newpower);

};

#endif // POWER_H
