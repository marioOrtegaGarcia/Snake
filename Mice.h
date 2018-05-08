//
//  Mice.h
//  glutapp
//
//  Created by Mario Ortega on 5/7/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Mice_h
#define Mice_h

#include <stdio.h>
#include "TexRect.h"
#include "Coord.h"
class Mice {
    TexRect* mouse;
    Coord* loc;
    float w = 2.0/40;
    float h = 1.83/40;
public:
    bool alive;
    Mice(float x= 0, float y=0);
    void kill();
    void draw();
    bool contains(float x, float y);
    ~Mice();
};

class taco : public Mice {
    TexRect* tacomouse;
    Coord* loc;
    float w = 2.0/40;
    float h = 1.83/40;
    bool up, down, left, right;
public:
    taco(float x = 0, float y = 0);
    void kill();
    void draw();
    void changeDirection(int key);
    void move(float step = 0.05);
    bool contains(float x, float y);
    ~taco();
};
#endif /* Mice_hpp */
