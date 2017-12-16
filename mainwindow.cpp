#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QAction>
#include <QColorDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imageArea = new ImageArea();

    createTollBarActions();

    setCentralWidget(imageArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setColor()
{
    QColor color = QColorDialog::getColor();
    if(color.isValid()){
        qDebug() << color;
        colorPixmap->fill(color);
        changeColor->setIcon(QIcon(*colorPixmap));
        imageArea->set_current_color(color);
    }
}

void MainWindow::getColor()
{

}

void MainWindow::createTollBarActions()
{
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

    colorPixmap = new QPixmap(40,40);
    colorPixmap->fill(imageArea->current_color());
    changeColor = ui->mainToolBar->addAction(*colorPixmap,"Цвет");
    connect(changeColor, SIGNAL(triggered()),this, SLOT(setColor()));
    changeColor->setToolTip("Цвет");

    eyeDropper = ui->mainToolBar->addAction(QIcon(":/icons/eyedropper_icon.png"),"Пипетка");
    connect(eyeDropper,SIGNAL(triggered(bool)),imageArea,SLOT(eyedropperToggle(bool)));
    eyeDropper->setCheckable(true);
    eyeDropper->setToolTip("Пипетка");
}
