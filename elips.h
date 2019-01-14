#pragma once
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include "rect.h"
class Elips: public Rect{
public:
    explicit Elips();
    ~Elips() override;
    void moving(const int& x1,const int& y1) override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
