#include "imagearea.h"
#include <QWheelEvent>
ImageArea::ImageArea(QWidget *parent)
{
    scene = new QGraphicsScene;
    image = new QImage(":/carina-nebula-nasa-esa-hubble.jpg");
    pixmap = QPixmap::fromImage(*image);
    pixmapItem = scene->addPixmap(pixmap);
    this->setScene(scene);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    space_pressed = false;
}

void ImageArea::wheelEvent(QWheelEvent *event)
{
    event->angleDelta().y() > 0 ? scale(1.1, 1.1) : scale(0.9, 0.9);
}

void ImageArea::mousePressEvent(QMouseEvent *event)
{
    if(space_pressed)
        setDragMode(QGraphicsView::ScrollHandDrag);

    QGraphicsView::mousePressEvent(event);
}

void ImageArea::mouseReleaseEvent(QMouseEvent *event)
{
    setDragMode(QGraphicsView::NoDrag);
    QGraphicsView::mouseReleaseEvent(event);
}

void ImageArea::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Space:
        space_pressed = true;
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}

void ImageArea::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Space:
        space_pressed = false;
        break;
    default:
        QGraphicsView::keyReleaseEvent(event);
    }
}
