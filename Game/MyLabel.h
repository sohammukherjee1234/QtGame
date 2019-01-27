#ifndef LABEL_H
#define LABEL_H




#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include<QObject>



class MyLabel:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
   public :
    int currpower;
   int scenewidth;
    int sceneheight;
    int startx;
    int starty;
    MyLabel(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *keyevent);

public slots:
    void drawfruit();
};
#endif // LABEL_H
