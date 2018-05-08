#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
/*
#include <vector>
#include "TexRect.h"
#include "AnimatedRect.h"
#include "Rect.h"
#include "Button.h"
#include "Snake.h"
#include "Mice.h"
#include "HighScores.h"
*/

#include "gameInfo.h"

class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);
    void specialKeyPress(int key);
    void specialKeyUp(int key);
    void idle();


    
    gameInfo* game;
    
    /*
    Score* score;
    AnimatedRect* explode;
    Snake* leonidas;
    TexRect* menu;
    TexRect* background;
    resetButton* reset;
    pauseButton* pause;
    HighScores* highScores;
    gameInfo *game;
    vector<Mice*> rats;
    vector<Rect*> home;
    */
};

#endif
