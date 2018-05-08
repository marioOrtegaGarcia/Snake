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
gameInfo::gameInfo() {
    gameOver = false;   // Game is not over when started
    gameMode = 0;
    // Draw the home buttons
    home.push_back(new Rect(-0.3, 0.55, 0.6, 0.25));
    home.push_back(new Rect(-0.3, -0.35, 0.6, 0.25));
    score = new Score();
    menu = new TexRect("images/menu.png", -1, 1, 2, 2);
    background = new TexRect("images/grass.jpeg", -1, .83, 2, 2);
    explode = new AnimatedRect("images/explosion.png", 9, 9, 0, 0 , 0.5 , 0.5);
    reset = new resetButton("images/reset.png", -1, 1, .167, .167);
    pause = new pauseButton("images/pause.png", .83, 1, .167, .167);
    leonidas = new Snake();
    highScores = new HighScores();
    rats.push_back(new Mice(0,0.28));
}

bool gameInfo::gameState(){
    return gameOver;
}

void gameInfo::draw() {
    if (gameMode == 0){           // Home Screen
        menu->draw();
        // Draw the two home buttons
        glColor3f(1.0, 0.0, 0.0);
        for (int i = 0; i < home.size(); i++){
            glBegin(GL_POLYGON);
            glVertex2f(home[i]->getX(), home[i]->getY());
            glVertex2f(home[i]->getX() + home[i]->getWidth(), home[i]->getY());
            glVertex2f(home[i]->getX() + home[i]->getWidth(), home[i]->getY() - home[i]->getHeight());
            glVertex2f(home[i]->getX(), home[i]->getY() - home[i]->getHeight());
            glEnd();
        }
        //Write "Play"
        string text;
        text = "Play";
        glColor3f(1.0, 1.0, 1.0);
        writeText(text.data(), 380, 430, 15);
        
        //Write "High Scores"
        string text2;
        text2 = "High Scores";
        glColor3f(1.0, 1.0, 1.0);
        writeText2(text2.data(), 365, 160, 15);
        
        
        
    }else if (gameMode == 1){     // Snake game
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        background->draw();
        score->draw();
        reset->draw();
        pause->draw();
        
        rats[0]->draw();
        leonidas->draw();
        explode->draw();
        
        
    }else if (gameMode == 2){     // High score screen
        // Draw the high score box
        glColor3f(1.0, 1.0, 1.0);
        glLineWidth(2.5);
        glBegin(GL_LINES);
        
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        
        glVertex2f(-0.5, 0.3);
        glVertex2f(0.5, 0.3);
        
        glVertex2f(-0.5, 0.1);
        glVertex2f(0.5, 0.1);
        
        glVertex2f(-0.5, -0.1);
        glVertex2f(0.5, -0.1);
        
        glVertex2f(-0.5, -0.3);
        glVertex2f(0.5, -0.3);
        
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        
        glVertex2f(-0.5, 0.5);
        glVertex2f(-0.5, -0.5);
        
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
        glEnd();
        
        // Write "High Scores"
        string text2;
        text2 = "High Scores";
        glColor3f(1.0, 1.0, 1.0);
        writeText2(text2.data(), 360, 460, 15);
        highScores->drawScores();
        reset->draw();
    }
}
void gameInfo::writeText(const char *text, int x, int y, int length){
    glMatrixMode(GL_PROJECTION);
    double *matrix = new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glLoadIdentity();
    glOrtho(0, 800, 0, 600, -5, 5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x,y);
    for(int i = 0; i < length; i++){
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);
}
//Can We Just call this functions giving it two different arrays?
void gameInfo::writeText2(const char *text2, int x, int y, int length){
    glMatrixMode(GL_PROJECTION);
    double *matrix = new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX, matrix);
    glLoadIdentity();
    glOrtho(0, 800, 0, 600, -5, 5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x,y);
    for(int i = 0; i < length; i++){
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text2[i]);
    }
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);
}
void gameInfo::passKeys(int key) {
    if (leonidas->alive && !pause->checkPauseClicked() && key >= 100 && key <= 103) {
        leonidas->changeDirection(key);
    }
}
void gameInfo::passMouseCoords(float x, float y) {
    if (gameMode == 0){                                           // Title Screen
        if (home[0]->contains(x, y)) gameMode = 1;                // Snake Game
        else if (home[1]->contains(x, y)) gameMode = 2;           // High Scores
    }else if (gameMode == 1 && !gameOver){
        checkIfOver();
    }else if (gameMode == 2 && !gameOver){
        checkIfOver();
    }
    
    if (pause->contains(x, y)){
        pause->changePause();
    }
    
    if (reset->contains(x, y)){
        //
        reset->resetClicked = true;
        gameOver = true;
        leonidas->alive = false;
        leonidas->~Snake();
        leonidas = new Snake();
        rats.clear();
        rats.push_back(new Mice(0,0.28));
        highScores->insertQueue(score->getScore());
        score->reset();
        explode->reset();
        gameMode = 0;
        gameOver = false;
    }
}
int gameInfo::getGameMode() {
    return gameMode;
}
bool gameInfo::checkIfOver() {
    return gameOver;
}
void gameInfo::endGame(){
    gameOver = true;
}

gameInfo::~gameInfo() {
    delete score;
    delete explode;
    delete leonidas;
    delete menu;
    delete background;
    delete reset;
    delete pause;
    delete highScores;
    while (rats.size() >= 1) {
        delete rats.back();
        rats.pop_back();
    }
    while (home.size() >= 1) {
        delete home.back();
        home.pop_back();
    }
}
