#ifndef RECT1_H
#define RECT1_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

class Rect1: public QObject, public QGraphicsItem{
Q_OBJECT
public:
    explicit Rect1(QObject *parent = 0);
    ~Rect1();
    double set_rect1_x(),set_rect1_y();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // RECT1_H
