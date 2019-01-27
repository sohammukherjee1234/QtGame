#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include<QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:

    void setup();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int width=50;
    int height=50;

    int locx=10;
    int locy=10;


private slots:


private:
    Ui::MainWindow *ui;

 protected:


};

#endif // MAINWINDOW_H
