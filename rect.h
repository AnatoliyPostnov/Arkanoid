#pragma once
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

class Rect: public QObject, public QGraphicsItem{
    Q_OBJECT
public:
    explicit Rect(QObject *parent, const int width,const int height);
    ~Rect();
    virtual void moving(const int& x1,const int& y1)=0;
protected:
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int width_;
    int height_;
};
