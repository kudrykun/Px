#include "scribblearea.h"
ScribbleArea::ScribbleArea(QWidget *parent) : QWidget(parent)
{
    image = new QImage(64,64,QImage::Format_ARGB32);
    image->fill(QColor(255,255,255));
    scale = 1;
    //image->save("testImage.png");
}

void ScribbleArea::paintEvent(QPaintEvent *event)
  {
      QPainter painter(this);
      painter.scale(scale,scale);
      QRect dirtyRect = event->rect();
      painter.drawImage(dirtyRect, *image, dirtyRect);
}

void ScribbleArea::wheelEvent(QWheelEvent *event)
{
    scale+=event->angleDelta().y()/360.0;
    this->setGeometry(4,4,height()*scale,height()*scale);
    qDebug() << scale;
    qDebug() << event->pos();
    update();
}
