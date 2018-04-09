#include "mainwidget.h"
#include "icon.h"
#include <QApplication>
#include <QDebug>
#include <QFile>


int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    Mainwidget w;
    w.resize(300,250);
    w.move(800,600);
    w.show();
    qDebug()<<QFile("/home/maxus/EditLine/third.png").exists();
    return app.exec();
}

