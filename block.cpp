#include "block.h"

Block::Block(const int& width,const int& height)
    :Rect(nullptr,width,height){
}

Block::~Block(){}

void Block::moving(const int& x1,const int& y1){
    setPos(mapToParent(x1,y1));
}

int Block::get_width(){
    return width_;
}

int Block::get_height(){
    return height_;
}
