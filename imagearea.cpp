#include "imagearea.h"
#include <QWheelEvent>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QAction>

ImageArea::ImageArea()
{
    space_pressed = false;
    drawingModeEnabled = false;
    erasingModeEnabled = false;

    scene = new QGraphicsScene;
    scene->setBackgroundBrush(QBrush(Qt::red));
    image = new QImage(":/carina-nebula-nasa-esa-hubble.jpg");
    pixmap = QPixmap::fromImage(*image);
    pixmapItem = scene->addPixmap(pixmap);
    this->setScene(scene);

    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

}

void ImageArea::wheelEvent(QWheelEvent *event)
{
    event->angleDelta().y() > 0 ? scale(1.1, 1.1) : scale(0.9, 0.9);
}

void ImageArea::mousePressEvent(QMouseEvent *event)
{
    if(space_pressed)                               //dragging
        setDragMode(QGraphicsView::ScrollHandDrag);
    else{                                           //drawing
        if(drawingModeEnabled){
            QPointF point(mapToScene(event->pos()));
            //scene->addRect(point.x(),point.y(),1,1);
            image->setPixel(point.x(),point.y(),QColor(76,76,76).rgb());

            pixmap = QPixmap::fromImage(*image);
            pixmapItem->setPixmap(pixmap);
        }
        if(erasingModeEnabled){
            QPointF point(mapToScene(event->pos()));
            //scene->addRect(point.x(),point.y(),1,1);
            image->setPixel(point.x(),point.y(),QColor(255,255,255).rgb());
            qDebug() << QColor::fromRgb(image->pixel(point.x(),point.y()));
            qDebug() << QColor::fromRgba(image->pixel(point.x(),point.y()));
            pixmap = QPixmap::fromImage(*image);
            pixmapItem->setPixmap(pixmap);
        }
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

void ImageArea::pencilToggle(bool checked)
{
    drawingModeEnabled = checked;
    qDebug() << "drawing";
}

void ImageArea::eraserToggle(bool checked)
{
    erasingModeEnabled = checked;
    qDebug() << "erasing";
}
