#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
    ,ui(new Ui::MainWindow)
    ,highscore_(0){
     ui->setupUi(this);
     this->resize(1000,1000);
     this->setFixedSize(416,346);
     QFont font;
     QFont font1;
     font.setPixelSize(60);
     font1.setPixelSize(30);
     ui->Arcanoid_game->setFont(font);
     ui->Highscore->setFont(font1);
     ui->next->hide();
     connect(ui->start,&QPushButton::clicked,this,&MainWindow::on_Start_clicked);
     connect(ui->next,&QPushButton::clicked,this,&MainWindow::on_Next_clicked);
     Exit();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::showMainWindow(){
    ui->next->hide();
    ui->highscore->display(highscore_);
    this->show();
}

void MainWindow::showGameOver(const int current){
    Highscore(current);
    game_over->Show(current,highscore_);
}

void MainWindow::showGameWin(const int current){
    Highscore(current);
    game_over->Win(current,highscore_);
}

void MainWindow::on_Next_clicked(){
    game_window->show();
    this->close();
    ui->highscore->display(highscore_);
}

void MainWindow::Show(const int current){
    this->show();
    Highscore(current);
    ui->highscore->display(highscore_);
}

void MainWindow::on_Start_clicked(){
    game_over=new Game_over();
    ui->next->show();
    //delete game_window;
    game_window=new GameWindow();
    connect(game_window,&GameWindow::ShowMainWindow,this,&MainWindow::Show);
    connect(game_window,&GameWindow::ShowGameOver,this,&MainWindow::showGameOver);
    connect(game_window,&GameWindow::YouWin,this,&MainWindow::showGameWin);
    connect(game_over,&Game_over::ShowMainWindow,this,&MainWindow::showMainWindow);
    game_window->show();
    this->close();
}

void MainWindow::Exit(){
    connect(ui->exit,&QPushButton::clicked,this,&MainWindow::close);
}

void MainWindow::Highscore(const int &current){
    if(highscore_<current){
        highscore_=current;
    }
}

