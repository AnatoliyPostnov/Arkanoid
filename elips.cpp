#include "elips.h"

Elips::Elips()
    :Rect(nullptr,10,10){
}

Elips::~Elips(){}

void Elips::moving(const int& x1,const int& y1){
    setPos(mapToParent(x1,y1));
}

void Elips::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget){
    painter->setBrush(Qt::black);
    painter->drawEllipse(0,0,10,10);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
