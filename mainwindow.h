#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scribblearea.h"
#include "imagearea.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void setColor();
    void getColor();
private:
    Ui::MainWindow *ui;
    void createTollBarActions();
    ImageArea *imageArea;
    QAction *pencilAction;
    QAction *eraserAction;
    QAction *changeColor;
    QAction *eyeDropper;
    QPixmap *colorPixmap;
};

#endif // MAINWINDOW_H
