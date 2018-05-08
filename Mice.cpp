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

taco::taco(float x, float y) {
    loc = new Coord(x,y);
    alive = true;
    up = down = left = right = false;
    tacomouse = new TexRect("images/tacomouse.png", x, y, w, h);
}

void taco::draw() {
    if (alive) {
        tacomouse->draw();
    }
}

void taco::kill(){
    alive = false;
    //delete this;
}

void taco::changeDirection(int key) {
    switch (key) {
        case 3:
            if (!right) {
                left = true;
                up = down = right = false;
            }
            break;
        case 2:
            if (!down) {
                up = true;
                left = right = down = false;
            }
            break;
        case 1:
            if (!left) {
                right = true;
                up = down = left = false;
            }
            break;
        case 0:
            if (!up) {
                down = true;
                left = right = up = false;
            }
            break;
        default:
            break;
    }
}

bool taco::contains(float mx, float my) {
    if (mx >= loc->x-(w/2) && mx <= loc->x+(w*1.5) && my <= loc->y+ (h/2) && my >= loc->y - (1.5 * h)) {
        kill();
        return true;
    }
    return false;
}

void taco::move(float step) {
    loc->x-=step;
    tacomouse->moveLeft(step);
}

taco::~taco() {
    delete tacomouse;
    delete loc;
}
