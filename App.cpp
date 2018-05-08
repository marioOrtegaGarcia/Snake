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
        
        //Move taco
        singleton->tacos[0]->move(.005);
        
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
            if(singleton->leonidas->shouldGrow(singleton->tacos, x, y)) {
                singleton->score->incScore(15);
                singleton->tacos[0]->changeDirection((int)(singleton->count) % 4);
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
    rats.push_back(new Mice(0,0.28));
    tacos.push_back(new taco(0.33,-0.28));
}

void App::specialKeyPress(int key){
    if (singleton->leonidas->alive && !singleton->pause->checkPauseClicked() && key >= 100 && key <= 103) {
        leonidas->changeDirection(key);
    }
}

void App::specialKeyUp(int key){
    
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
        tacos[0]->draw();
        leonidas->draw();
        explode->draw();
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
    
    if (game->gameMode == 0){                                           // Title Screen
        if (home[0]->contains(x, y)) game->gameMode = 1;                // Snake Game
        else if (home[1]->contains(x, y)) game->gameMode = 2;           // High Scores
    }else if (game->gameMode == 1 && !game->gameOver){
        game->checkIfOver();
    }else if (game->gameMode == 2 && !game->gameOver){
        game->checkIfOver();
    }
    
    if (pause->contains(x, y)){
        pause->changePause();
    }
    
    if (reset->contains(x, y)){
        reset->resetClicked = true;
        game->gameOver = true;
        leonidas->alive = false;
        leonidas->~Snake();
        leonidas = new Snake();
        rats.clear();
        //tacos.clear();
        rats.push_back(new Mice(-0.2,0.6));
        tacos.push_back(new taco(-0.2,-0.6));
        score->reset();
        game->gameMode = 0;
    }
    
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
        while (rats.size() >= 1) {
            delete rats.back();
            rats.pop_back();
            delete tacos.back();
            tacos.pop_back();
        }
        while (home.size() >= 1) {
            delete home.back();
            home.pop_back();
        }
        delete this;
        exit(0);
    }
    
    //if (key == '/') game->pause->changePause();
    //if (key == ' ') mouseDown(-0.99, 0.99);
    
}
