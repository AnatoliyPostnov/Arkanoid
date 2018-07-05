#include "elips.h"
#include "rect.h"
#include <iostream>
#include <QGraphicsEllipseItem>
#include <QTimerEvent>

Elips::Elips(QObject *parent) :
    QObject(parent), QGraphicsItem() {}

Elips::~Elips(){}

void Elips::moving(int x1,int y1){
      setPos(mapToParent(x1, y1));
      set_x();
      set_y();
}
double Elips::set_x(){
    return x();
}
double Elips::set_y(){
    return y();
}
QRectF Elips::boundingRect() const
{

   return QRectF(0,0, 10, 10);
}
void Elips::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);     /// Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawEllipse(0,0,10,10);  /// Рисуем полигон
    Q_UNUSED(option);
    Q_UNUSED(widget);
}


