#pragma once
#include "gamewindow.h"
#include "game_over.h"
#include <QMainWindow>


namespace Ui {
    class MainWindow;
}
class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void on_Start_clicked();
    void on_Next_clicked();
    void Show(const int current);
    void showGameOver(const int current);
    void showMainWindow();
    void showGameWin(const int current);
protected:
    void Start();
    void Exit();
    void Highscore(const int& current);
private:
    Ui::MainWindow *ui;
    GameWindow* game_window;
    Game_over* game_over;
    int highscore_;
};




