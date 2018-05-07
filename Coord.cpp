//
//  Coord.cpp
//  glutapp
//
//  Created by Mario Ortega on 5/6/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "Coord.h"
Coord::Coord (int x, int y) {
    this->x = x;
    this->y = y;
}
void Coord::moveUp(int step) {
    y+=step;
}
void Coord::moveDown(int step) {
    y-=step;
}
void Coord::moveRight(int step) {
    x+=step;
}
void Coord::moveLeft(int step) {
    x-=step;
}
Coord::~Coord (){
    
}
