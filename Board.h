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
#include "Mice.h"
class Board {
    int boardSize = 40;
public:
    Mice* gameBoard[40][40];
    Board();
    bool containsMice(int x, int y);
    void draw();
    void placeMice();
    Mice* get(int x, int y);
    ~Board();
    
};

#endif /* Board_h */
