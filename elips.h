#ifndef ELIPS_H
#define ELIPS_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>


class Elips: public QObject, public QGraphicsItem{
   Q_OBJECT
public:
    explicit Elips(QObject *parent = 0);
    ~Elips();
    void moving(int x1, int y1);
    double set_x(),set_y();
signals:
    //void signalCollisionElips(QGraphicsItem *point);
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    //int x1=5,y1=-5;


};

#endif // ELIPS_H


