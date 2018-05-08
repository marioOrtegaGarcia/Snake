//
//  Coord.cpp
//  glutapp
//
//  Created by Mario Ortega on 5/6/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "Coord.h"
Coord::Coord (float x, float y) {
    this->x = x;
    this->y = y;
}
void Coord::moveUp(float step) {
    y+=step;
}
void Coord::moveDown(float step) {
    y-=step;
}
void Coord::moveLeft(float step) {
    x-=step;
}
void Coord::moveRight(float step) {
    x+=step;
}
Coord::~Coord (){
    
}
