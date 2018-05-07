//
//  Board.cpp
//  glutapp
//
//  Created by Mario Ortega on 5/6/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "Board.h"
#include <iostream>

Board::Board(){
    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < boardSize; j++)
            gameBoard[i][j] = nullptr;
}
bool Board::containsMice(int x, int y) {
    if (gameBoard[x][y] != nullptr) {
        gameBoard[x][y]->kill();
        return true;
    }
    return false;
}
void Board::placeMice() {
    int x = (rand() % (boardSize-1)) + 1;
    int  y = (rand() % (boardSize-1)) + 1;
    std::cout << "(" << x << "," << y << ")";
    gameBoard[x][y] = new Mice((float)x,(float)y);
    //gameBoard[x][y] = new Mice();
}
void Board::draw() {
    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < boardSize; j++)
            if (gameBoard[i][j] != nullptr)
                gameBoard[i][j]->draw();
}
Mice*  Board::get(int x, int y) {
    return gameBoard[x+boardSize/2][y-boardSize/2];
}
Board::~Board(){
    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < boardSize; j++)
            delete gameBoard[i][j];
}
