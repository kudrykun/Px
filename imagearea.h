#ifndef IMAGEAREA_H
#define IMAGEAREA_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
class ImageArea : public QGraphicsView
{
    Q_OBJECT

public:
    ImageArea();
protected:
    void wheelEvent(QWheelEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
public slots:
    void pencil();
private:
    QGraphicsScene *scene;
    QGraphicsPixmapItem *pixmapItem;
    QPixmap pixmap;
    QImage *image;
    bool space_pressed;
};

#endif // IMAGEAREA_H
