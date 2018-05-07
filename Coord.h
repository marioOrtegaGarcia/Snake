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
    float x;
    float y;
    Coord (float x = 0.0, float y = 0.0);
    void moveUp(float step = 0.05);
    void moveDown(float step = 0.05);
    void moveLeft(float step = 0.05);
    void moveRight(float step = 0.05);
    virtual ~Coord();
};
#endif /* Coord_h */
