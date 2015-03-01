#include "mainwindow.h"
#include "gamewindow.h"
//#include "fanfan.qrc"
#include <QApplication>
#include <QDebug>
#include <QString>
#include <QHBoxLayout>
#include <QMediaPlayer>
//#include <QDir>
#include <QResource>
#include <QSound>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Окно администратора
    MainWindow w;
    w.setWindowTitle("Угадай мелодию");
    w.show();

    // Окно с игрой
    GameWindow w2;
    w2.setWindowTitle("Угадай мелодию");
    w2.show();

    QObject::connect(&w, SIGNAL(mysignal(QString)), &w2 ,SLOT(myslot(QString)));
    QObject::connect(&w, SIGNAL(pressitem(int, int)), &w2 ,SLOT(pressitemslot(int, int)));

    QString appdir(a.applicationDirPath());
//    qDebug() << "DirApp: " << appdir;
    QDir x;
    QString path;
    path = x.currentPath();
    return a.exec();
}
