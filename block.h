#pragma once
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include "rect.h"

class Block: public Rect{
public:
    explicit Block(const int& width,const int& height);
    ~Block() override;
    void moving(const int& x1,const int& y1) override;
    int get_width();
    int get_height();
};
