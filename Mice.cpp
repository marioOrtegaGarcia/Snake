//
//  Mice.cpp
//  glutapp
//
//  Created by Mario Ortega on 5/7/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//
#include <iostream>
#include "Mice.h"

Mice::Mice(float x, float y) {
    loc = new Coord(x,y);
    alive = true;
    mouse = new TexRect("images/mouse.png", x, y, w, h);
}

void Mice::kill(){
    alive = false;
}

void Mice::draw() {
    if (alive) {
        mouse->draw();
    }
}

bool Mice::contains(float mx, float my) {
    if (mx >= loc->x-(w/2) && mx <= loc->x+(w*1.5) && my <= loc->y+ (h/2) && my >= loc->y - (1.5 * h)) {
        kill();
        return true;
    }
    return false;
}

Mice::~Mice(){
    delete mouse;
    delete loc;
}
