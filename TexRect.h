#ifndef TexRect_h
#define TexRect_h

#if defined WIN32
#include <freeglut.h>
#include "../windows/SOIL.h"
#elif defined __APPLE__
#include <GLUT/glut.h>
#include <SOIL.h>
#else
#include <GL/freeglut.h>
#include <SOIL.h>
#endif
#include <string>
using namespace std;

class TexRect {
public:
    float x;
    float y;
    float w;
    float h;
    GLuint texture_id;
    
    
    TexRect (const char*, float, float, float, float);
    
    void draw();
    
    bool contains(float, float);
    
    void moveUp(float rate=0.01);
    void moveDown(float rate=0.01);
    void moveLeft(float rate=0.01);
    void moveRight(float rate=0.01);
    
    void jump();
    
    bool rising;
    bool movingLeft;
    
    float xinc;
    float yinc;
};

class resetButton : public TexRect {
    
public:
    resetButton (const char* filename, float x, float y, float w, float h) : TexRect (filename, x, y, w, h){}
    
    bool resetClicked;
    
    bool checkResetClicked() {
        return resetClicked;
    }
    
    bool contains(float mx, float my) {
        return mx >= -1 && mx <= -1 + 0.167 && my <= 1 && my >= 1 - 0.167;
    }
    
};

class pauseButton : public TexRect {
    
public:
    pauseButton (const char* filename, float x, float y, float w, float h) : TexRect (filename, x, y, w, h){}
    
    bool pauseClicked;
    
    bool checkPauseClicked() {
        return pauseClicked;
    }
    
    bool contains(float mx, float my){
        return mx >= 0.83 && mx <= 0.83 + 0.167 && my <= 1 && my >= 1 - 0.167;
    }
};

class Score {
    int score;
    int highScores[5];
//    priority_queue highscores[5];
public:
    Score() {
        score = 0;
    }
    int getScore() {
        return score;
    }
    void incScore(int num) {
        score += num;
    }
    void draw() {
        
    }
    void save() {
        
    }
};

#endif
