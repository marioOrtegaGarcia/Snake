//
//  Snake.h
//  glutapp
//
//  Created by Mario Ortega on 5/6/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Snake_h
#define Snake_h

#include <stdio.h>
#include <list>
#include "Coord.h"
#include "Board.h"
using namespace std;

class Snake {
private:
    list<Coord*> snake;
    bool up, down, left, right;
    bool grow;
    
public:
    bool alive;
    Snake();
    void changeDirection(int key);
    void move();
    void shouldGrow();
    bool atMouse();
    bool collisionCheck();
    void draw();
    ~Snake();
};

#endif /* Snake_h */
