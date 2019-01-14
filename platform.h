#pragma once
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include "rect.h"
class Platform: public Rect{
public:
    explicit Platform();
    ~Platform() override;
    void moving(const int& x1,const int& y1) override;
};
