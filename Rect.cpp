//
//  Rect.cpp
//  glutapp
//
//  Created by Mario Ortega on 5/7/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "Rect.h"
Rect::Rect(float a, float b, float c, float d){
    x = a;
    y = b;
    width = c;
    height = d;
}

float Rect::getX(){
    return x;
}

float Rect::getY(){
    return y;
}

float Rect::getWidth(){
    return width;
}

float Rect::getHeight(){
    return height;
}

void Rect::setX(float input){
    x = input;
}

void Rect::setY(float input){
    y = input;
}

void Rect::setWidth(float input){
    width = input;
}

void Rect::setHeight(float input){
    height = input;
}

void Rect::click(){
    if (!pressed) pressed = true;
    else pressed = false;
}

void Rect::unClick() {
    pressed = false;
}

bool Rect::contains(float inputX, float inputY){
    return ((inputX > x && inputX < (x + width)) && (inputY < y && inputY > (y - height)));
}

Rect::~Rect(){
    
    }
