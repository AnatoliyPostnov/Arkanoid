#include "rect.h"

Rect::Rect(QObject *parent, const int width,const int height)
    :QObject(parent)
    ,QGraphicsItem()
    ,width_(width)
    ,height_(height){
}

Rect::~Rect(){}

QRectF Rect::boundingRect() const{
    return QRectF(0,0,width_,height_);
}
void Rect::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget){
    QPolygon polygon;
    polygon << QPoint(0,0) << QPoint(width_,0) << QPoint(width_,height_)
            << QPoint(0,height_);
    painter->setBrush(Qt::red);
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
