//
//  HighScores.hpp
//  glutapp
//
//  Created by Erik Aguilar on 5/7/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef HighScores_h
#define HighScores_h

#include "App.h"
#include <stdio.h>
#include <string>

using namespace std;

class HighScores {
    
public:
    
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
    
    void drawScores(){
        string place1 = "First Place:";
        glColor3f(1.0, 1.0, 1.0);
        S1(place1.data(), 255, 410, 15);
        
        string place2 = "Second Place:";
        glColor3f(1.0, 1.0, 1.0);
        S2(place2.data(), 255, 350, 15);
        
        string place3 = "Third Place:";
        glColor3f(1.0, 1.0, 1.0);
        S3(place3.data(), 255, 290, 15);
        
        string place4 = "Fourth Place:";
        glColor3f(1.0, 1.0, 1.0);
        S4(place4.data(), 255, 230, 15);
        
        string place5 = "Fifth Place:";
        glColor3f(1.0, 1.0, 1.0);
        S5(place5.data(), 255, 170, 15);
    }
};

#endif /* HighScores_h */
