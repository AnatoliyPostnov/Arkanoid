#include "rect.h"
#include <iostream>


Rect::Rect(QObject *parent) :
    QObject(parent), QGraphicsItem() {}

Rect::~Rect(){}

void Rect::moving(int x1, int y1)
{
    if (this->isEnabled())
        setPos(mapToParent(x1, y1));
    if(x()==-20)
        setX(0);
    if(x()==420)
        setX(400);
}

double Rect::set_rect_x(){
    return x();
}


QRectF Rect::boundingRect() const
{
    return QRectF(0,0, 100, 20);
}

void Rect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;   /// Используем класс полигона, чтобы отрисовать фигуру
    /// Помещаем координаты точек в полигональную модель
    polygon << QPoint(0,0) << QPoint(100,0) << QPoint(100,20) << QPoint(0, 20);
    painter->setBrush(Qt::red);     /// Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawPolygon(polygon);  /// Рисуем полигон
    Q_UNUSED(option);
    Q_UNUSED(widget);

}


