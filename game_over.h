#pragma once
#include <QWidget>
#include <QMouseEvent>
#include "gamewindow.h"
namespace Ui {
class Game_over;
}

class Game_over : public QWidget
{
    Q_OBJECT

public:
    explicit Game_over(QWidget *parent = nullptr);
    ~Game_over();
    void Show(const int current,const int highscore);
    void Win(const int current,const int highscore);
signals:
    void ShowMainWindow(const int sc);
protected:
    virtual void mousePressEvent(QMouseEvent *event);
private:
    Ui::Game_over *ui;
};

