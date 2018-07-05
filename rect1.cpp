#include "rect1.h"


Rect1::Rect1(QObject *parent) :
    QObject(parent), QGraphicsItem() {}

Rect1::~Rect1(){}

double Rect1::set_rect1_x(){
    return x();
}
double Rect1::set_rect1_y(){
    return y();
}


QRectF Rect1::boundingRect() const
{
    return QRectF(0,0, 30, 15);
}

void Rect1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;   /// Используем класс полигона, чтобы отрисовать фигуру
    /// Помещаем координаты точек в полигональную модель
    polygon << QPoint(0,0) << QPoint(30,0) << QPoint(30,15) << QPoint(0, 15);
    painter->setBrush(Qt::green);     /// Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawPolygon(polygon);  /// Рисуем полигон
    Q_UNUSED(option);
    Q_UNUSED(widget);

}
