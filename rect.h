#ifndef RECT_H
#define RECT_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

class Rect: public QObject, public QGraphicsItem{
Q_OBJECT
public:
    explicit Rect(QObject *parent = 0);
    ~Rect();
    void moving(int x, int y);
    double set_rect_x();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};
#endif // RECT_H



