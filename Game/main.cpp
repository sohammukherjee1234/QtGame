
#include <QApplication>

#include "game.h"

game *newgame;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    newgame=new game();
    newgame->show();


    return a.exec();
}
