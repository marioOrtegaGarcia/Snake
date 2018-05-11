//
//  HighScores.hpp
//  glutapp
//
//  Created by Erik Aguilar on 5/7/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef HighScores_h
#define HighScores_h

//#include "App.h"
//#include "TexRect.h"

#include <stdio.h>
#include <string>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

struct compare {
    bool operator()(const int& l, const int& r){
        return l > r;
    }
};

class HighScores {
    priority_queue<int, vector<int>, compare> topScores;
public:
    HighScores(){
        for(int newScore : {0,0,0,0,0})
            topScores.push(newScore);
    }
    void insertQueue(int newScore){
        int lowestScore = topScores.top();
        //cout << lowestScore << endl;
        if(lowestScore < newScore)
        {
            topScores.pop();
            topScores.push(newScore);
        }
    }
    
    void S1(const char *place1, int x, int y, int length){
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
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)place1[i]);
        }
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glLoadMatrixd(matrix);
        glMatrixMode(GL_MODELVIEW);
    }
    /*
    void S2(const char *place2, int x, int y, int length){
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
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)place2[i]);
        }
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glLoadMatrixd(matrix);
        glMatrixMode(GL_MODELVIEW);
    }
    
    void S3(const char *place3, int x, int y, int length){
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
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)place3[i]);
        }
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glLoadMatrixd(matrix);
        glMatrixMode(GL_MODELVIEW);
    }
    
    void S4(const char *place4, int x, int y, int length){
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
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)place4[i]);
        }
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glLoadMatrixd(matrix);
        glMatrixMode(GL_MODELVIEW);
    }
    
    void S5(const char *place5, int x, int y, int length){
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
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)place5[i]);
        }
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glLoadMatrixd(matrix);
        glMatrixMode(GL_MODELVIEW);
    }
    */
    void drawScores(){
        int val;
        
        string place5 = "Fifth Place:";
        val = topScores.top();
        topScores.pop();
        place5 += to_string(val);
        glColor3f(1.0, 1.0, 1.0);
        S1(place5.data(), 255, 170, 15);
        
        string place4 = "Fourth Place:";
        val = topScores.top();
        place4 += to_string(val);
        topScores.pop();
        glColor3f(1.0, 1.0, 1.0);
        S1(place4.data(), 255, 230, 15);
        
        string place3 = "Third Place:";
        val = topScores.top();
        place3 += to_string(val);
        topScores.pop();
        glColor3f(1.0, 1.0, 1.0);
        S1(place3.data(), 255, 290, 15);
        
        string place2 = "Second Place:";
        val = topScores.top();
        place2 += to_string(val);
        topScores.pop();
        glColor3f(1.0, 1.0, 1.0);
        S1(place2.data(), 255, 350, 15);
        
        string place1 = "First Place:";
        val = topScores.top();
        place1 += to_string(val);
        topScores.pop();
        glColor3f(1.0, 1.0, 1.0);
        S1(place1.data(), 255, 410, 15);
        
    }
};

#endif /* HighScores_h */
