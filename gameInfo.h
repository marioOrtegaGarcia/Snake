//
//  gameInfo.h
//  glutapp
//
//  Created by Mario Ortega on 5/7/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef gameInfo_h
#define gameInfo_h
#include <vector>
#include "TexRect.h"
#include "AnimatedRect.h"
#include "Rect.h"
#include "Button.h"
#include "Snake.h"
#include "Mice.h"
#include "HighScores.h"

#include <stdio.h>
struct gameInfo{
    int gameMode;       // 0 for home screen, 1 to play game, 2 for high scores
    gameInfo();
    bool gameOver;
    float x, y, w, h;
    bool gameState();
    void endGame();
    bool checkIfOver();
    void draw();
    void writeText(const char *text, int x, int y, int length);
    void writeText2(const char *text2, int x, int y, int length);
    void passKeys(int key);
    void passMouseCoords(float x, float y);
    int getGameMode();
    ~gameInfo();
    
    
    
    float count = 0, mult = -1;
    Score* score;
    AnimatedRect* explode;
    Snake* leonidas;
    TexRect* menu;
    TexRect* background;
    resetButton* reset;
    pauseButton* pause;
    HighScores* highScores;
    
    vector<Mice*> rats;
    vector<Rect*> home;
};
#endif /* gameInfo_h */
