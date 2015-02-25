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
    w.setWindowTitle("Name That Tune!");
    w.show();

    // Окно с игрой
    GameWindow w2;
    w2.setWindowTitle("Угадай мелодию");
    w2.show();

    QString appdir(a.applicationDirPath());
    qDebug() << "DirApp: " << appdir;
    QMediaPlayer *player = new QMediaPlayer;
    //player->setMedia(QUrl::fromLocalFile(QDir::toNativeSeparators("mp3/Fail.mp3")));
    //player->setMedia(QUrl::fromLocalFile("mp3/Fail.mp3"));
    QDir x;
    //x = QDir::​current();
    QString path;
    path = x.currentPath();
    qDebug() << path;
    //player->setMedia(QUrl::fromLocalFile(path + "/mp3/Success.mp3"));
    //player->setVolume(100);
    player->play();
    //QSound::play("mp3/Fail.mp3");

    return a.exec();
}
