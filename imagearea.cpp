#include "imagearea.h"
#include <QWheelEvent>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QGraphicsPixmapItem>

ImageArea::ImageArea()
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
    else{
        QPointF point(mapToScene(event->pos()));
        //scene->addRect(point.x(),point.y(),1,1);
        image->setPixel(point.x(),point.y(),Qt::transparent);

        pixmap = QPixmap::fromImage(*image);
        pixmapItem->setPixmap(pixmap);

        qDebug() << "draw";
        qDebug() << point;
        qDebug() << point.toPoint();
    }
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

void ImageArea::pencil()
{
    qDebug() << "ok bro";
}
