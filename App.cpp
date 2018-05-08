#include "App.h"
//#include <vector>

using namespace std;
static App* singleton;


void app_timer(int value){
    if (singleton->game->gameState() && !singleton->game->explode->done()) {
        singleton->game->explode->advance();
    }
    
    //Game Not Paused
    if (!singleton->game->pause->checkPauseClicked()) {
        
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
    
    game = new gameInfo();
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
    
    /*
     if (game->gameMode == 0){           // Home Screen
     // Draw the two home buttons
     menu->draw();
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
     
     }else if (game->gameMode == 1){     // Snake game
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     background->draw();
     score->draw();
     reset->draw();
     pause->draw();
     
     rats[0]->draw();
     leonidas->draw();
     explode->draw();
     app_timer(1);
     
     }else if (game->gameMode == 2){     // High score screen
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
     */
    
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
    
    //if (key == '/') game->pause->changePause();
    //if (key == ' ') mouseDown(-0.99, 0.99);
    
}
