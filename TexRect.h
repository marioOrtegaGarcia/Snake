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


class Score {

public:
    
    int score;
    
    Score() {
        score = 0;
    }
    int getScore() {
        return score;
    }
    void incScore(int num) {
        score += num;
    }
    void writeText(const char *text, int x, int y, int length)
    {
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
        for(int i = 0; i < length; i++) {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
        }
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glLoadMatrixd(matrix);
        glMatrixMode(GL_MODELVIEW);
        
    }
    void draw() {
        glClearColor(0.0, 0.0, 0.0, 1.0);
        string text;
        text = "SCORE: " + to_string(score);
        glColor3f(1.0, 1.0, 1.0);
        writeText(text.data(), 350, 560, 15);
    }
    void save() {
        
    }
    void reset() {
        score = 0;
    }
};
#endif
