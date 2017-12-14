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
    void wheelEvent(QWheelEvent *event) override;   // scrolling
    void mousePressEvent(QMouseEvent *event) override; // drawing and dragging if space is pressed
    void mouseReleaseEvent(QMouseEvent *event) override; // stop dragging
    void keyPressEvent(QKeyEvent *event) override; //catching space pressing
    void keyReleaseEvent(QKeyEvent *event) override; //catching space releasing
public slots:
    void pencilToggle(bool checked);
    void eraserToggle(bool checked);
private:
    QGraphicsScene *scene;
    QGraphicsPixmapItem *pixmapItem;
    QPixmap pixmap;
    QImage *image;

    bool space_pressed;
    bool drawingModeEnabled;
    bool erasingModeEnabled;
};

#endif // IMAGEAREA_H
