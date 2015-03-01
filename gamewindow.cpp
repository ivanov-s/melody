#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QDebug>
#include <QApplication>
#include <QDebug>
#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QMediaPlayer>
#include <QDir>
#include <QResource>
#include <QSound>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
}

GameWindow::~GameWindow()
{
    delete ui;
}
void GameWindow::pressitemslot(int i, int j)
{
    ui->box->itemAtPosition(i,j)->widget()->setDisabled(true);
}
void GameWindow::myslot(QString s)
{
    qDebug() << "Сигнал открытия директории"<< s;
    if(!(ui->box->isEmpty()))
    {
        QLayoutItem *child;
        while ((child = ui->box->takeAt(0)) != 0)
            delete child->widget();

    }
    QDir dir,tmpdir;
    QString tmpstr;
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
            QString tmpname = "Мелодия ";
            tmpname += QString::number(j+1);
            button = new QPushButton(tmpname);
            ui->box->addWidget(button, i, j + 1);
        }
    }
    ui->box->update();
    dir = 0;
}
