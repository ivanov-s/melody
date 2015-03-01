#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QMediaPlayer>

QMediaPlayer *player = new QMediaPlayer;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myslot()
{
//    qDebug() << ((QPushButton*)sender())->text();
//    qDebug() << ((QPushButton*)sender())->whatsThis();
    player->stop();
    QString frombutton;
    frombutton = ((QPushButton*)sender())->whatsThis();
    QStringList LIST;
    LIST=frombutton.split(" ");
    int i = LIST[LIST.count()-2].toInt();
    int j = LIST[LIST.count()-1].toInt();
    j++;
    emit(pressitem(i, j));
    frombutton = frombutton.split(".mp3")[0];
    frombutton+=".mp3";
    player->setMedia(QUrl::fromLocalFile(QDir::toNativeSeparators(frombutton)));
    player->setVolume(100);
    player->play();
    ((QPushButton*)sender())->setDisabled(true);
}

void MainWindow::opendir()
{
    if(!(ui->box->isEmpty()))
    {
        QLayoutItem *child;
        while ((child = ui->box->takeAt(0)) != 0)
            delete child->widget();

    }
    QFileDialog dial(this);
    QDir dir,tmpdir;
    QString s = dial.getExistingDirectory(), tmpstr;
    QPushButton* button;
    QLabel *label;
    dir.setPath(s);
    dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);

    for(unsigned int i = 0 ; i < dir.count(); i++)
    {
        label = new QLabel(dir[i]);
        ui->box->addWidget(label, i, 0);

        tmpstr = dir[i];
        tmpdir.setPath(s);
        tmpdir.cd(tmpstr);
        tmpdir.setFilter(QDir::Files | QDir::NoDotAndDotDot);

        for(unsigned int j = 0; j < tmpdir.count(); j++)
        {
            button = new QPushButton(tmpdir[j]);
//            qDebug() << tmpdir.absolutePath()+tmpdir[j];
            QObject::connect(button, SIGNAL(clicked()), this,  SLOT(myslot()));
            ui->box->addWidget(button, i, j + 1);
            button->setWhatsThis(tmpdir.absolutePath()+"/"+tmpdir[j]+" "+QString::number(i)+" "+QString::number(j));
            qDebug() << button->whatsThis();
        }
    }
    ui->box->update();
//    qDebug()<<ui->box->itemAtPosition(1,1)->widget();
    dir = 0;
    emit(mysignal(s));
}
