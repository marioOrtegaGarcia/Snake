#include "App.h"
//#include <vector>

using namespace std;
static App* singleton;


void app_timer(int value){
    if (singleton->game->isGameOver() && !singleton->game->explode->done()) {
        singleton->game->explode->advance();
    }
    
    //Game Not Paused
    if (!singleton->game->pauseB->gamePaused()) {
        
        //Leonidas Alive
        if (singleton->game->leonidas->alive) {
            singleton->game->count++;
            if (singleton->game->count > 40) {
                singleton->game->count = 0;
            }
            float x =  singleton->game->count / 50.0;
            float y =  singleton->game->count / 60.0;
            if ((int)singleton->game->count % 2 == 0) x = x * singleton->game->mult;
            if ((int)singleton->game->count % 3 == 0) y = y * singleton->game->mult;
            
            singleton->game->leonidas->move();
            singleton->game->leonidas->collisionCheck();
            if(singleton->game->leonidas->shouldGrow(singleton->game->rats, x, y)) {
                singleton->game->score->incScore(5);
            }
            //Leonidas Dead
        }else {
            if (singleton->game->leonidas->length() > (singleton->game->score->getScore()*2)) {
                Coord* head = singleton->game->leonidas->getHead();
                singleton->game->explode->relocate(head->x, head->y);
            }
            singleton->game->endGame();
            singleton->game->explode->animate();
            singleton->game->leonidas->vanish();
        }
    }
    //Draws animation for Gameover calls itself at a rate of 100ms
    if (singleton->game->gameOver) {
        singleton->redraw();
        glutTimerFunc(200, app_timer, value);
    } else {
        //Calls itself while game isnt over at a rate of 16 ms
        if (true){
            singleton->redraw();
            glutTimerFunc(100, app_timer, value);
        }
    }
}



App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    singleton = this;
    mx = 0.0;
    my = 0.0;
    
    game = new gameState();
}
void App::specialKeyPress(int key){game->passKeys(key);}
void App::specialKeyUp(int key){}
void App::draw() {
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    float oneThird = 0.333;
    float twoThirds = 0.667;
    game->draw();
    if (game->getGameMode() == 1) {
        app_timer(1);
    }
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;

    game->passMouseCoords(mx, my);
    // Redraw the scene
    redraw();
}
void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
}
void App::idle(){}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        delete game;
        delete this;
        exit(0);
    }
    
    if (key == '/') game->pauseB->changePause();
    if (key == ' ') mouseDown(-0.99, 0.99);
    
}
