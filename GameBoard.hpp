//
//  GameBoard.hpp
//  glutapp
//
//  Created by Mario Ortega on 4/26/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef GameBoard_hpp
#define GameBoard_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class Board {
    int* gameBoard[10][10];

public:
    Board();
    ~Board();

};
#endif /* GameBoard_hpp */
