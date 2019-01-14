#pragma once
#include <QWidget>
#include <QMouseEvent>
#include "graphicsscene.h"
#include "platform.h"
#include "elips.h"
#include "block.h"
#include <QTimer>
#include <QTimerEvent>

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
signals:
    void ShowGameOver(const int s);
    void ShowMainWindow(const int sc);
    void YouWin(const int sc);
public slots:
    void keyPressEvent(QKeyEvent *ke);
    void keyReleaseEvent(QKeyEvent *ke);
    void timerEvent(QTimerEvent *event=0);
    void Start_Elips();
    void Start_Game();
protected:
    virtual void mousePressEvent(QMouseEvent *event);
    bool Elips_Movement();
    void Set_Level();
    void Level_1();
    void Level_2();
    void Level_3(int k);
    void Level_4(int k);
    Block* set_block(const int& width,const int& height,
                    const int x_pos,const int y_pos);
    bool collision_event_handling();
    bool hit_top(Block* it);
    bool hit_bottom(Block* it);
    bool hit_left(Block* it);
    bool hit_right(Block* it);
private:
    Ui::GameWindow *ui;
    QGraphicsScene *scene;
    Platform *platform;
    Elips *elips;
    QTimer *timer;
    Block *block;
    QVector <Block*> Blocks;
    int x;
    int y;
    int live;
    int level;
    int score;
    bool is_moving_left;
    bool is_moving_right;
};
