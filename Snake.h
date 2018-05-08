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
#include <vector>
#include <list>
#include "Coord.h"
#include "Board.h"
#include "Mice.h"

using namespace std;

class Snake {
private:
    list<Coord*> snake;
    bool up, down, left, right;
    int grow;
    float girth;
public:
    bool alive;
    
    Snake();
    void changeDirection(int key);
    void move(float step = 0.015);
    bool shouldGrow(vector<Mice*> &rats);
    bool atMouse();
    void collisionCheck();
    void draw();
    ~Snake();
};



#endif /* Snake_h */
