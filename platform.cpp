#include "platform.h"
Platform::Platform()
    :Rect(nullptr,40,10){
}

Platform::~Platform(){}

void Platform::moving(const int& x1,const int& y1){
    setPos(mapToParent(x1,y1));
}
