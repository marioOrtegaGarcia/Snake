//
//  gameInfo.h
//  glutapp
//
//  Created by Mario Ortega on 5/7/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef gameInfo_h
#define gameInfo_h

#include <stdio.h>
struct gameInfo{
    int gameMode = 0;       // 0 for home screen, 1 to play game, 2 for high scores
    int turn = 0;
    int gameBoard[9];
    bool gameOver;
    float x, y, w, h;
    
    gameInfo();
    bool gameState();
    void endGame();
    void checkIfOver();};
#endif /* gameInfo_h */
