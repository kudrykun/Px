#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QGridLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imageArea = new ImageArea();
    pencilAction = ui->mainToolBar->addAction(QIcon(":/icons/pencil_icon.svg"),"Карандаш",imageArea,SLOT(pencil()));
    pencilAction->setCheckable(true);
    setCentralWidget(imageArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}
