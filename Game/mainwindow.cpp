#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <string>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>
#include <unistd.h>
#include<QRect>
#include<QSize>
#include<QDebug>
#include<QKeyEvent>
#include<QLabel>
#include "MyLabel.h"


QImage img=QImage(700,700,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




   /* QPixmap background("/home/soham/Game/images/snow.jpg");
    background=background.scaled(this->size(),Qt::IgnoreAspectRatio);

    QPalette pal;
    pal.setBrush(QPalette::Background,background);
    this->setPalette(pal);*/

}



void MainWindow::setup()
{
    QPixmap image("/home/soham/Game/images/standing-still.png");

   MyLabel * person=new MyLabel();
   ui->horizontalLayout->addWidget();

   person->setFocus();
   person->pixmap(image);
   person->setGeometry(QRect(locx,locy,locx+width,locy+height));
   person->mask(image.mask());
   person->show();
}

/*void MainWindow::keypres(QKeyEvent *keyevent)
{
    if(keyevent->key()==Qt::Key_D)
    {
        locx+=10;
        ui->person->setGeometry(QRect(locx,locy,locx+width,locy+height));
        QPixmap image("/home/soham/Game/images/standing-still.png");
        image=image.scaled(QSize(width,height));
        ui->person->setPixmap(image);
        ui->person->setMask(image.mask());


    }
}*/

MainWindow::~MainWindow()
{
    delete ui;
}
