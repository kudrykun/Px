#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imageArea = new ImageArea();

    pencilAction = ui->mainToolBar->addAction(QIcon(":/icons/pencil_icon.png"),"Карандаш");
    connect(pencilAction,SIGNAL(triggered(bool)),imageArea,SLOT(pencilToggle(bool)));
    pencilAction->setCheckable(true);
    pencilAction->setShortcut(QKeySequence("Ctrl+P"));
    pencilAction->setToolTip("Карандаш");

    eraserAction = ui->mainToolBar->addAction(QIcon(":/icons/eraser_icon.png"),"Ластик");
    connect(eraserAction,SIGNAL(triggered(bool)),imageArea,SLOT(eraserToggle(bool)));
    eraserAction->setCheckable(true);
    eraserAction->setShortcut(QKeySequence("Ctrl+E"));
    eraserAction->setToolTip("Ластик");

    setCentralWidget(imageArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}
