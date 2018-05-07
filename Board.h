//
//  Board.h
//  glutapp
//
//  Created by Mario Ortega on 5/6/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Board_h
#define Board_h

#include <stdio.h>
#include <cstdlib>
#include "Coord.h"
#include "TexRect.h"
class Mice {
    TexRect* mouse;
public:
    bool alive;
    Mice(float x= 0, float y=0) {
        float width = 2.0/40;
        float height = 1.83/40;
        alive = true;
        mouse = new TexRect("images/mouse.png", -1 + (width * x), 0.83 - (height * y), width, height);
        //mouse = new TexRect("images/mouse.png", .5, .5, width, height);
    }
    void kill(){
        alive = false;
        delete this;
    }
    void draw() {
        mouse->draw();
    }
    ~Mice(){}
};
class Board {
    Mice* gameBoard[40][40];
    int boardSize = 40;
public:
    Board();
    bool containsMice(int x, int y);
    void draw();
    void placeMice();
    Mice* get(int x, int y);
    ~Board();
    
};

#endif /* Board_h */
