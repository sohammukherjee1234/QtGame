#include "power.h"
#include<QString>
#include <QFont>


power::power(QGraphicsTextItem *parent):QGraphicsTextItem(parent)
{
    score=0;
    setPlainText(QString("Power: "+QString::number(score)));;
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));

}

void power::update(int newpower){
    score=newpower;
    setPlainText(QString("Power: "+QString::number(score)));;
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}
