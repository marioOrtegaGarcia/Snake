//
//  Mice.cpp
//  glutapp
//
//  Created by Mario Ortega on 5/7/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "Mice.h"
Mice::Mice(float x, float y) {
    float width = 2.0/40;
    float height = 1.83/40;
    alive = true;
    mouse = new TexRect("images/mouse.png", -1 + (width * x), 0.83 - (height * y), width, height);
    //mouse = new TexRect("images/mouse.png", .5, .5, width, height);
}
void Mice::kill(){
    alive = false;
    delete this;
}
void Mice::draw() {
    mouse->draw();
}
Mice::~Mice(){}
