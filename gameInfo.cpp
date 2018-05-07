//
//  gameInfo.cpp
//  glutapp
//
//  Created by Mario Ortega on 5/7/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "gameInfo.h"
#include <iostream>
using namespace std;
gameInfo::gameInfo(){
    gameOver = false;   // Game is not over when started
    
    for (int i = 0; i < 9; i ++){
        gameBoard[i] = 0;
    }
}

bool gameInfo::gameState(){
    return gameOver;
}

void gameInfo::endGame(){
    gameOver = true;
}

void gameInfo::checkIfOver(){
    // Horizontal wins
    if (gameBoard[0] == 1 && gameBoard[1] == 1 && gameBoard[2] == 1)
        cout << "Player 1 wins" << endl;
    }
