#include "graphicsscene.h"

//void GraphicsView_::send_event_signal(){
//    emit event_signal();
//}

void GraphicsScene::event_signal(){
    QMetaObject::activate(this,&staticMetaObject,0,0);
}

//void GraphicsScene::mousePressEvent(QMouseEvent *event){
//    if(event->MouseButtonPress){
//       emit event_signal();
//    }
//}
