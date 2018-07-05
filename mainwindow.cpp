#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rect.h"
#include "rect1.h"
#include <iostream>
#include "elips.h"
#include "math.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    this->resize(600,600);          // Задаем размеры виджета, то есть окна
    this->setFixedSize(600,600);    // Фиксируем размеры виджета

    QWidget *base=new QWidget;

    body=new QVBoxLayout(base);
    this->setCentralWidget(base);

    QGraphicsView *graphicsView = new QGraphicsView();
    graphicsView->setEnabled(false);
    body->addWidget(graphicsView);

    scene=new QGraphicsScene();
    graphicsView->setScene(scene);  // установка графической сцены в graphicsView
    rect=new Rect();
    elips=new Elips();
    pb=new QPushButton("START",this);
    body->addWidget(pb);
    connect(pb, SIGNAL(clicked()), this, SLOT(timer_start()));

    scene->setSceneRect(0,0,500,500);
    scene->addLine(0,500,500,500,QPen(Qt::black));
    scene->addLine(0,0,0,500,QPen(Qt::black));
    scene->addLine(500,0,500,500,QPen(Qt::black));
    scene->addLine(0,0,500,0,QPen(Qt::black));

    scene->addItem(rect);
    rect->setPos(200,480);
    scene->addItem(elips);
    elips->setPos(240,470);

    create_rect1(40);




    connect(this,SIGNAL(X1()),this,SLOT(hit()));
    connect(this,SIGNAL(X2()),this,SLOT(collision()));
    }
MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::get_x(){
     x_elips=elips->set_x();
}
void MainWindow::get_y(){
    y_elips=elips->set_y();
}

void MainWindow::create_rect1(int amount){
    int a=1,b=1;
    int col=50;
    int row=50;
    for(int i=0;i<amount;i++){
       Rect1 *rect1=new Rect1();
       rect1->setPos(col * a, row * b);
       if(a==8){
           a=0;
           b++;
       }
       a++;
       if(b==8) b=1;
       scene->addItem(rect1);
       rects1.push_back(rect1);
    }
}


void MainWindow::keyPressEvent(QKeyEvent *ke){
    switch(ke->key()){
    case Qt::Key_A:
        rect->moving(-20, 0);
        break;

    case Qt::Key_D:
        rect->moving(20, 0);
        break;
    }
}

void MainWindow::timer_start(){
    timer= new QTimer;
    connect(timer, SIGNAL(timeout()),SLOT(start_elips()));
    timer->start(50);
}


void MainWindow::start_elips(){
    elips->moving(x,y);
    get_x();
    get_y();
    emit X2();
    if( x_elips==0||x_elips<0){
        x=-x;
    }
    if( x_elips==490||x_elips>490){
        x=-x;
    }
    if( y_elips==0){
        y=-y;
    }
    if( y_elips==470){
        emit X1();
        if(x_elips>rect->set_rect_x() && x_elips<rect->set_rect_x()+20 && x>0){
            if(a==2) {
                x=2*x;
                a=1;
            }
            x=-x;
        }
        if(x_elips>rect->set_rect_x()+20 && x_elips<rect->set_rect_x()+40){
            if(a==2&&x>0) {
                x=-2*x;
                a=1;
            }
            if(a==2&&x<0) {
                x=2*x;
                a=1;
            }
            if(x>0) {
                x=-x;
            }
        }
        if(x_elips>rect->set_rect_x()+80 && x_elips<rect->set_rect_x()+100&&x<0){
            if(a==2) {
                x=2*x;
                a=1;
            }
            x=-x;
        }
        if(x_elips>rect->set_rect_x()+60 && x_elips<rect->set_rect_x()+80){
            if(a==2&&x<0) {
                x=-2*x;
                a=1;
            }
            if(a==2&&x>0) {
                x=2*x;
                a=1;
            }
            if(x<0) {
                x=-x;
            }
        }
        if(x_elips>rect->set_rect_x()+40 && x_elips<rect->set_rect_x()+60&&a==1){
            x=0.5*x;
            a=2;
        }
        y=-y;

    }
}

void MainWindow:: hit(){
    get_x();
    if((abs(x_elips)<abs(rect->x())||abs(x_elips)>abs(rect->x()+100))&&b==5){
        scene->removeItem(rect);
        scene->removeItem(elips);
        foreach (QGraphicsItem *rect1, rects1) {
             scene->removeItem(rect1);
        }
        scene->addText("GAME OVER");
    }
}

void MainWindow::collision(){
    foreach (QGraphicsItem *rect1, rects1) {
        if(x_elips > rect1->x()-9&&x_elips < rect1->x()+29&&y_elips==rect1->y()+15)
        {
            scene->removeItem(rect1);
            rects1.removeOne(rect1);
            y=-y;
        }
        if(x_elips > rect1->x()-9&&x_elips < rect1->x()+29&&y_elips+10==rect1->y())
        {
            scene->removeItem(rect1);
            rects1.removeOne(rect1);
            y=-y;
        }
        if(y_elips < rect1->y()+14&&y_elips > rect1->y()-9&&x_elips+10==rect1->x())
        {
            scene->removeItem(rect1);
            rects1.removeOne(rect1);
            x=-x;
        }
        if(y_elips < rect1->y()+14&&y_elips > rect1->y()-9&&x_elips==rect1->x()+30)
        {
            scene->removeItem(rect1);
            rects1.removeOne(rect1);
            x=-x;
        }
        if(rects1.size()==0){
            scene->removeItem(rect);
            scene->removeItem(elips);
            scene->addText("YOU WIN");
            b=3;
        }

    }

}

