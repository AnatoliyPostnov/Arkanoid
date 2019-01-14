#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    :QWidget(parent)
    ,ui(new Ui::GameWindow)
    ,x(5)
    ,y(-5)
    ,live(3)
    ,level(1)
    ,score(0)
    ,is_moving_left(false)
    ,is_moving_right(false){
    ui->setupUi(this);
    this->resize(1000,1000);
    this->setFixedSize(478,383);
    QFont font;
    font.setPixelSize(18);
    ui->Level->setFont(font);
    ui->Score->setFont(font);
    ui->Life->setFont(font);
    ui->label->setFont(font);
    ui->label_2->setFont(font);
    ui->label_4->setFont(font);
    ui->view->setFixedWidth(290);
    ui->view->setFixedHeight(290);
    startTimer(40);
    Start_Game();
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::mousePressEvent(QMouseEvent *event){
    if(event->MouseButtonPress){
        timer->stop();
        this->close();
        emit ShowMainWindow(score);
    }
}

void GameWindow::keyPressEvent(QKeyEvent *ke){
    switch(ke->nativeVirtualKey()){
    case Qt::Key_A:
        is_moving_left = true;
        break;
    case Qt::Key_D:
        is_moving_right = true;
        break;
    case Qt::Key_S:
        if(timer->isActive()){
            timer->stop();
        }else{
            timer->start(50);
        }
        break;
    }
}

void GameWindow::keyReleaseEvent(QKeyEvent *ke){
    switch(ke->nativeVirtualKey()){
    case Qt::Key_A:
        is_moving_left = false;
        break;
    case Qt::Key_D:
        is_moving_right = false;
        break;
    }
}

void GameWindow::timerEvent(QTimerEvent *){
    if (is_moving_left){
        if(static_cast<int>(platform->x())!=0){
            platform->moving(-10,0);
        }
    }
    if (is_moving_right){
        if(static_cast<int>(platform->x())!=240){
            platform->moving(10,0);
        }
    }
}

void GameWindow::Start_Game(){
    scene=new QGraphicsScene();
    ui->view->setScene(scene);
    scene->addLine(0,280,280,280,QPen(Qt::black));
    scene->addLine(0,0,0,280,QPen(Qt::black));
    scene->addLine(280,0,280,280,QPen(Qt::black));
    scene->addLine(0,0,280,0,QPen(Qt::black));
    platform=new Platform();
    elips=new Elips();
    scene->addItem(platform);
    scene->addItem(elips);
    platform->setPos(120,270);
    elips->setPos(140,260);
    x=5;
    y=-5;
    ui->life->display(live);
    ui->level->display(level);
    ui->score->display(score);
    Set_Level();
    timer=new QTimer();
    connect(timer,&QTimer::timeout,this,&GameWindow::Start_Elips);
}

Block* GameWindow::set_block(const int& width,const int& height,
                            const int x_pos,const int y_pos){
    block=new Block(width,height);
    scene->addItem(block);
    block->setPos(x_pos,y_pos);
    return block;
}

void GameWindow::Level_1(){
    for(int i=20,j=20;i<=220;i+=50){
        Blocks.push_back(set_block(40,40,i,j));
        if(j==20){j=80;}
        else     {j=20;}
    }
}

void GameWindow::Level_2(){
    Level_1();
    for(int i=20,j=140;i<=220;i+=100){
        Blocks.push_back(set_block(40,40,i,j));
    }
}

void GameWindow::Level_3(int k){
    for(int i=40,j=20;;i+=30){
        Blocks.push_back(set_block(20,10,i,j));
        if(i==220){
            i=10;
            j+=20;
            --k;
        }
        if(k==0){
            break;
        }
    }
}

void GameWindow::Level_4(int k){
    for(int i=40,j=20;;i+=20){
        Blocks.push_back(set_block(20,10,i,j));
        if(i==220){
            i=20;
            j+=20;
            --k;
        }
        if(k==0){
            break;
        }
    }
}

void GameWindow::Set_Level(){
    switch(level){
        case 1:
            Level_1();
            break;
        case 2:
            Level_2();
            break;
        case 3:
            Level_3(3);
            break;
        case 4:
            Level_3(6);
            break;
        case 5:
            Level_4(3);
            break;
        case 6:
            Level_4(6);
            break;
        default:
            emit YouWin(score);
    }
}

bool GameWindow::hit_top(Block* it){
    if(static_cast<int>(elips->y())+10==static_cast<int>(it->y())){
        if(elips->x()+10>it->x()&&
           elips->x()<it->x()+it->get_width()){
            y=-y;
            return true;
        }
    }
    return false;
}

bool GameWindow::hit_bottom(Block* it){
    if(static_cast<int>(elips->y())==static_cast<int>(it->y()+it->get_height())){
        if(elips->x()+10>it->x()&&
           elips->x()<it->x()+it->get_width()){
            y=-y;
            return true;
        }
    }
    return false;
}

bool GameWindow::hit_left(Block* it){
    if(static_cast<int>(elips->x())+10==static_cast<int>(it->x())){
        if(elips->y()+10>it->y()&&
           elips->y()<it->y()+it->get_height()){
            x=-x;
            return true;
        }
    }
    return false;
}

bool GameWindow::hit_right(Block* it){
    if(static_cast<int>(elips->x())==static_cast<int>(it->x()+it->get_width())){
        if(elips->y()+10>it->y()&&
            elips->y()<it->y()+it->get_height()){
            x=-x;
            return true;
        }
    }
    return false;
}

bool GameWindow::collision_event_handling(){
    for(auto it=Blocks.begin();it<Blocks.end();++it){
        if(x>0&&y>0){
            if(static_cast<int>(elips->x())+10==static_cast<int>((*it)->x())&&
               static_cast<int>(elips->y())+10==static_cast<int>((*it)->y())){
                x=-x;
                y=-y;
                scene->removeItem(*it);
                Blocks.erase(it);
                ui->score->display(++score);
            }else if(hit_left(*it)||hit_top(*it)){
                scene->removeItem(*it);
                Blocks.erase(it);
                ui->score->display(++score);
            }
        }else if(x<0&&y>0){
            if(static_cast<int>(elips->x())==static_cast<int>((*it)->x()+(*it)->get_width())&&
               static_cast<int>(elips->y())+10==static_cast<int>((*it)->y())){
                x=-x;
                y=-y;
                scene->removeItem(*it);
                Blocks.erase(it);
                ui->score->display(++score);
            }else if(hit_right(*it)||hit_top(*it)){
                scene->removeItem(*it);
                Blocks.erase(it);
                ui->score->display(++score);
            }
        }else if(x>0&&y<0){
            if(static_cast<int>(elips->x())+10==static_cast<int>((*it)->x())&&
               static_cast<int>(elips->y())==static_cast<int>((*it)->y()+(*it)->get_height())){
                x=-x;
                y=-y;
                scene->removeItem(*it);
                Blocks.erase(it);
                ui->score->display(++score);
            }else if(hit_left(*it)||hit_bottom(*it)){
                scene->removeItem(*it);
                Blocks.erase(it);
                ui->score->display(++score);
            }
        }else if(x<0&&y<0){
            if(static_cast<int>(elips->x())==static_cast<int>((*it)->x()+(*it)->get_width())&&
               static_cast<int>(elips->y())==static_cast<int>((*it)->y()+(*it)->get_height())){
                x=-x;
                y=-y;
                scene->removeItem(*it);
                Blocks.erase(it);
                ui->score->display(++score);
            }else if(hit_right(*it)||hit_bottom(*it)){
                scene->removeItem(*it);
                Blocks.erase(it);
                ui->score->display(++score);
            }
        }
    }
    if(Blocks.size()==0){
        return true;
    }else{return false;}
}

void GameWindow::Start_Elips(){
    elips->moving(x,y);
    if(Elips_Movement()){
        if(collision_event_handling()){
            ++level;
            timer->stop();
            delete scene;
            Start_Game();
        }
    }else{
        ui->life->display(--live);
        if(live==0){
            timer->stop();
            emit ShowGameOver(score);
            this->close();
        }
        timer->stop();
        elips->setPos(140,260);
        x=5;
        y=-5;
    }
}

bool GameWindow::Elips_Movement(){
    if(static_cast<int>(elips->x())==270||static_cast<int>(elips->x())==0){
        x=-x;
    }
    if(static_cast<int>(elips->y())==0){
        y=-y;
    }
    if(static_cast<int>(elips->y())==260){
        if(static_cast<int>(platform->x())==static_cast<int>(elips->x())){
           if(x>0){x=-x;}
           if(static_cast<int>(elips->x())==0){x=-x;}
           y=-y;
        }else if(static_cast<int>(platform->x())+30==static_cast<int>(elips->x())){
           if(x<0){x=-x;}
           if(static_cast<int>(elips->x())==270){x=-x;}
           y=-y;
        }else if(platform->x()+10<=elips->x()&&platform->x()+30>elips->x()){
           y=-y;
        }
    }
    if(static_cast<int>(elips->y())==270){
        return false;
    }else{
        return true;
    }
}
