//
//  Coord.h
//  glutapp
//
//  Created by Mario Ortega on 5/6/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Coord_h
#define Coord_h

#include <stdio.h>
struct Coord {
    int x;
    int y;
    Coord (int x = 0, int y = 0);
    void moveUp(int step = 0.1);
    void moveDown(int step = 0.1);
    void moveLeft(int step = 0.1 );
    void moveRight(int step = 0.1);
    virtual ~Coord();
};
#endif /* Coord_h */
