//
//  Coord.hpp
//  glutapp
//
//  Created by Mario Ortega on 5/6/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Coord_hpp
#define Coord_hpp

#include <stdio.h>
struct Coord {
    int x;
    int y;
    Coord (int x = 0, int y = 0);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    virtual ~Coord();
};
#endif /* Coord_hpp */
