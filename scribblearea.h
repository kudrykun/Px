#ifndef SCRIBBLEAREA_H
#define SCRIBBLEAREA_H

#include <QObject>
#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QRect>
#include <QPaintEvent>
#include <QDebug>
class ScribbleArea : public QWidget
{
    Q_OBJECT
public:
    explicit ScribbleArea(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
signals:

public slots:

private:
    QImage *image;
    qreal scale;
};

#endif // SCRIBBLEAREA_H
