#include "game_over.h"
#include "ui_game_over.h"

Game_over::Game_over(QWidget *parent)
    :QWidget(parent)
    ,ui(new Ui::Game_over){
    ui->setupUi(this);
    this->resize(1000,1000);
    this->setFixedSize(430,330);
    QFont font;
    QFont font1;
    font.setPixelSize(45);
    font1.setPixelSize(30);
    ui->game_over->setFont(font);
    ui->you_win->setFont(font);
    ui->Highscore->setFont(font1);
    ui->Current->setFont(font1);
    ui->you_win->hide();
}

Game_over::~Game_over(){
    delete ui;
}

void Game_over::Show(const int current,const int highscore){
    this->show();
    ui->highscore->display(highscore);
    ui->current->display(current);
}

void Game_over::Win(const int current, const int highscore){
    this->show();
    ui->highscore->display(highscore);
    ui->current->display(current);
    ui->game_over->hide();
    ui->you_win->show();
}

void Game_over::mousePressEvent(QMouseEvent *event){
    if(event->MouseButtonPress){
        this->deleteLater();
        emit ShowMainWindow(0);
    }
}
