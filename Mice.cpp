//
//  Mice.cpp
//  glutapp
//
//  Created by Mario Ortega on 5/7/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//
#include <iostream>
using namespace std;
#include "Mice.h"
Mice::Mice(float x, float y) {
    loc = new Coord(x,y);
    alive = true;
    mouse = new TexRect("images/mouse.png", x, y, w, h);
    //mouse = new TexRect("images/mouse.png", .5, .5, width, height);
}
void Mice::kill(){
    alive = false;
    //delete this;
}
void Mice::draw() {
    if (alive) {
        mouse->draw();
    }
}
bool Mice::contains(float mx, float my) {
    if (mx >= loc->x && mx <= loc->x+w && my <= loc->y && my >= loc->y - h) {
        
        kill();
        return true;
    }
    return false;
}
Mice::~Mice(){
    delete mouse;
    delete loc;
}
