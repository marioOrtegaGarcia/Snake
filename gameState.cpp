//
//  gameState.cpp
//  glutapp
//
//  Created by Mario Ortega on 5/7/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "gameState.h"

gameState::gameState() {
    gameOver = false;   //Game Statrted
    gameMode = 0;       //GameMode {(0 -> Menu Screen), (1 -> Game Screen), (2 -> High Scores)}
    home.push_back(new Rect(-0.3, 0.55, 0.6, 0.25)); //Top Menu Button
    home.push_back(new Rect(-0.3, -0.35, 0.6, 0.25));//Bottom Menu Button
    score = new Score();
    menu = new TexRect("images/menu.png", -1, 1, 2, 2);
    background = new TexRect("images/grass.jpeg", -1, .83, 2, 2);
    explode = new AnimatedRect("images/explosion.png", 9, 9, 0, 0 , 0.5 , 0.5);
    resetB = new resetButton("images/reset.png", -1, 1, .167, .167);
    pauseB = new pauseButton("images/pause.png", .83, 1, .167, .167);
    leonidas = new Snake();
    highScores = new HighScores();
    rats.push_back(new Mice(0,0.28));
}

void gameState::displayMenu() {
    // Home Screen
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
    writeText(text2.data(), 365, 160, 15);
}

void gameState::displayGameScreen() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    background->draw();
    score->draw();
    resetB->draw();
    pauseB->draw();
    
    rats[0]->draw();
    leonidas->draw();
    explode->draw();
}

void gameState::displayTopScores() {
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
    writeText(text2.data(), 360, 460, 15);
    highScores->drawScores();
    resetB->draw();
}

void gameState::draw() {
    if      (gameMode == 0) displayMenu();
    else if (gameMode == 1) displayGameScreen();
    else if (gameMode == 2) displayTopScores();
}

void gameState::writeText(const char *text, int x, int y, int length){
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

void gameState::passKeys(int key) {
    if (leonidas->alive && !pauseB->gamePaused() && key >= 100 && key <= 103)
        leonidas->changeDirection(key);
}

void gameState::passMouseCoords(float x, float y) {
    if (gameMode == 0){                                           // Title Screen
        if      (home[0]->contains(x, y)) gameMode = 1;           // Snake Game
        else if (home[1]->contains(x, y)) gameMode = 2;           // High Scores
    }
    if (pauseB->contains(x, y)) pauseB->changePause();
    
    if (resetB->contains(x, y)) resetGame();
}

int gameState::getGameMode() {
    return gameMode;
}

bool gameState::isGameOver(){
    return gameOver;
}

void gameState::endGame(){
    gameOver = true;
}

void gameState::resetGame() {
    resetB->resetClicked = true;
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

gameState::~gameState() {
    delete score;
    delete explode;
    delete leonidas;
    delete menu;
    delete background;
    delete resetB;
    delete pauseB;
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
