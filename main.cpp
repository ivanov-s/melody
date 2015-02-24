#include "mainwindow.h"
//#include "fanfan.qrc"
#include <QApplication>
#include <QDebug>
#include <QString>
#include <QHBoxLayout>
#include <QMediaPlayer>
//#include <QDir>
#include <QResource>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Name That Tune!");

//    QWidget* pw=new QWidget(&w);
//    QPalette pal;
//    pal.setBrush(pw->backgroundRole(),QBrush(QPixmap("image.jpg")));
//    pw->setPalette(pal);
//    pw->setAutoFillBackground(true);

//    w.showMaximized();
    w.show();
    QString appdir(a.applicationDirPath());
    qDebug() << "DirApp: " << appdir;
    QMediaPlayer *player = new QMediaPlayer;
//    player->setMedia(QUrl::fromLocalFile(QDir::toNativeSeparators(":/mp3/Fail.mp3")));
    player->setMedia(QUrl::fromLocalFile(QDir::toNativeSeparators(":/mp3/Fail.mp3")));
    player->setVolume(100);
    player->play();
    return a.exec();
}
