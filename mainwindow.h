#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QWidget>
#include <QGraphicsScene>
#include <QShortcut>
#include <QTimer>
#include "rect.h"
#include "rect1.h"
#include "elips.h"
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QVector>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
   Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     void get_x(),get_y();
private:
    Ui::MainWindow *ui;
    Rect *rect;
    Elips *elips;
    QTimer *timer;
    QVBoxLayout *base_layout;
    QGraphicsScene *scene;
    QVBoxLayout *body;
    QVector <QGraphicsItem *> rects1;
    QPushButton *pb;
    int x=5,y=-5;
    double x_elips, y_elips;
    void create_rect1(int amount);
    int a=1,b=5;

public slots:
    void keyPressEvent(QKeyEvent *ke);
    void start_elips();
    void hit();
    void collision();
    void timer_start();
signals:
    void X1();
    void X2();
};


#endif // MAINWINDOW_H










