//
//  gameState.h
//  glutapp
//
//  Created by Mario Ortega on 5/7/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef gameState_h
#define gameState_h
#include <vector>
#include <iostream>
#include "TexRect.h"
#include "AnimatedRect.h"
#include "Rect.h"
#include "Button.h"
#include "Snake.h"
#include "Mice.h"
#include "HighScores.h"

#include <stdio.h>
struct gameState{
    int gameMode;       
    bool gameOver;
    
    float count = 0, mult = -1;
    Score* score;
    AnimatedRect* explode;
    Snake* leonidas;
    TexRect* menu;
    TexRect* background;
    resetButton* resetB;
    pauseButton* pauseB;
    HighScores* highScores;
    
    vector<Mice*> rats;
    vector<Rect*> home;
    vector<taco*> tacos;
    
    gameState();
    void displayMenu();
    void displayGameScreen();
    void displayTopScores();
    void draw();
    void writeText(const char *text, int x, int y, int length);
    void passKeys(int key);
    void passMouseCoords(float x, float y);
    int getGameMode();
    bool isGameOver();
    void endGame();
    void resetGame();
    ~gameState();
    

};
#endif /* gameState_h */
