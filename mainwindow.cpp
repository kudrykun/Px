#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QGridLayout>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    area = new ScribbleArea();
    ui->setupUi(this);
    //setCentralWidget(area);
    setCentralWidget(ui->scrollArea);
    ui->scrollArea->setWidget(area);

    //centralWidget()->setGeometry(200,100,area->width()+50,area->height());
    //qDebug() << centralWidget()->x();
}

MainWindow::~MainWindow()
{
    delete ui;
}
