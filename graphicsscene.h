#ifndef GRAPHICSVIEW__H
#define GRAPHICSVIEW__H
#include <QGraphicsView>
#include <QMouseEvent>
class GraphicsScene : public QGraphicsScene{
public:
    GraphicsScene(QWidget *parent = 0);
//    void send_event_signal();
signals:
    void event_signal();
//protected:
//    virtual void mousePressEvent(QMouseEvent *event);
};

#endif // GRAPHICSVIEW__H
