#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    qDebug() << "Hello";
//    QPushButton* Sen = new QPushButton(this->sender()->children());
    //Sen = this->sender()->;
    qDebug() << ((QPushButton*)sender())->text();
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
    dir.setPath(s);
    dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);

    for(unsigned int i = 0 ; i < dir.count(); i++)
    {
        button = new QPushButton(dir[i]);


        ui->box->addWidget(button, i, 0);

        tmpstr = dir[i];
        tmpdir.setPath(s);
        tmpdir.cd(tmpstr);
        tmpdir.setFilter(QDir::Files | QDir::NoDotAndDotDot);

        for(unsigned int j = 0; j < tmpdir.count(); j++)
        {
//            qDebug()<<"sysle";
            button = new QPushButton(tmpdir[j]);
            qDebug() << button->text();
            QObject::connect(button, SIGNAL(clicked()), this,  SLOT(myslot()));
            ui->box->addWidget(button, i, j + 1);
        }
    }
    ui->box->update();
    dir = 0;
}
