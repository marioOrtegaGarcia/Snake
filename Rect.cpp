//
//  Rect.cpp
//  glutapp
//
//  Created by Mario Ortega on 5/7/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "Rect.h"
Rect::Rect(float x, float y, float w, float h){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

float Rect::getX(){return x;}

float Rect::getY(){return y;}

float Rect::getWidth(){return w;}

float Rect::getHeight(){return h;}

void Rect::setX(float input){x = input;}

void Rect::setY(float input){y = input;}

void Rect::setWidth(float input){w = input;}

void Rect::setHeight(float input){h = input;}

void Rect::click(){
    if (!pressed) pressed = true;
    else          pressed = false;
}

void Rect::unClick() {pressed = false;}

bool Rect::contains(float mx, float my)
{return ((mx > x && mx < (x + w))   &&
         (my < y && my > (y - h))
         );}

Rect::~Rect(){
}
