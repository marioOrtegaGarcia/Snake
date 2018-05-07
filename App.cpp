#include "App.h"
#include <vector>

using namespace std;
static App* singleton;

void app_timer(int value){
    if (singleton->leonidas->alive && !singleton->pause->checkPauseClicked()) {
        singleton->leonidas->move();
        singleton->leonidas->collisionCheck();
    }
    
    //Draws animation for Gameover calls itself at a rate of 100ms
    if (singleton->game_over) {
        //singleton->redraw();
        glutTimerFunc(100, app_timer, value);
    } else {
        //Calls itself while game isnt over at a rate of 16 ms
        if (true){
            singleton->redraw();
            glutTimerFunc(100, app_timer, value);
        }
    }
}



struct Rect{
    float x, y, width, height;
    bool pressed = false;
    
    Rect(float a, float b, float c, float d){
        x = a;
        y = b;
        width = c;
        height = d;
    }
    
    float getX(){
        return x;
    }
    
    float getY(){
        return y;
    }
    
    float getWidth(){
        return width;
    }
    
    float getHeight(){
        return height;
    }
    
    void setX(float input){
        x = input;
    }
    
    void setY(float input){
        y = input;
    }
    
    void setWidth(float input){
        width = input;
    }
    
    void setHeight(float input){
        height = input;
    }
    
    void click(){
        if (!pressed) pressed = true;
        else pressed = false;
    }
    
    void unClick() {
        pressed = false;
    }
    
    bool contains(float inputX, float inputY){
        return ((inputX > x && inputX < (x + width)) && (inputY < y && inputY > (y - height)));
    }
    
    ~Rect(){
        
    }
};

void writeText(const char *text, int x, int y, int length){
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
void writeText2(const char *text2, int x, int y, int length){
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

vector<Rect*> home;


App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    
    singleton = this;
    mx = 0.0;
    my = 0.0;
    
    // Draw the home buttons
    home.push_back(new Rect(-0.3, 0.55, 0.6, 0.25));
    home.push_back(new Rect(-0.3, -0.35, 0.6, 0.25));
    
    game_over = false;
    score = new Score();
    board = new Board();
    board->placeMice();
    
    background = new TexRect("images/grass.jpeg", -1, .83, 2, 2);
    reset = new resetButton("images/reset.png", -1, 1, .167, .167);
    pause = new pauseButton("images/pause.png", .83, 1, .167, .167);
    leonidas = new Snake();
    highScores = new HighScores();
    
}

void App::specialKeyPress(int key){
    if (singleton->leonidas->alive && !singleton->pause->checkPauseClicked() && key >= 100 && key <= 103) {
        leonidas->changeDirection(key);
    }
}

void App::specialKeyUp(int key){
    
}

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
        board->draw();
        leonidas->draw();
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

void App::idle(){
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        delete score;
        delete board;
        delete leonidas;
        delete background;
        delete reset;
        delete pause;
        delete this;
        exit(0);
    }
    
    if (key == ' '){
        singleton->leonidas->shouldGrow();
    }
}
