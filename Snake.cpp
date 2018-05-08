//
//  Snake.cpp
//  glutapp
//
//  Created by Mario Ortega on 5/6/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "Snake.h"
#include <iostream>
#include <math.h>


//Creates the snake at the Center
Snake::Snake() {
    girth = 2.0/40;
    up = down = left = right = false;
    alive = true;
    
    grow = 10;
    snake.push_front(new Coord(0.0,0.0));
}

//Changes Bool Valuse for Directions
void Snake::changeDirection(int key) {
    switch (key) {
        case 100:
            if (!right) {
                left = true;
                up = down = right = false;
            }
            break;
        case 101:
            if (!down) {
                up = true;
                left = right = down = false;
            }
            break;
        case 102:
            if (!left) {
                right = true;
                up = down = left = false;
            }
            break;
        case 103:
            if (!up) {
                down = true;
                left = right = up = false;
            }
            break;
        default:
            break;
    }
}

void Snake::move(float step) {
    Coord* head = new Coord(snake.front()->x,snake.front()->y);
    if (up) head->moveUp(step);
    if (down) head->moveDown(step);
    if (left) head->moveLeft(step);
    if (right) head->moveRight(step);
    snake.push_front(head);
    if (grow == 0)
        snake.pop_back();
    else
        grow--;
}

//Increases snake length once it eats
bool Snake::shouldGrow(std::vector<Mice*> &rats, float x, float y) {
    for (int i = 0; i < rats.size(); i++) {
        if (rats[i]->contains(snake.front()->x, snake.front()->y)) {
            grow+=10;
            rats.erase(rats.begin() + i);
            bool neg = false;
            if(rand()%2 == 0) neg = true;
            
            rats.push_back(new Mice(x, y));
            return true;
        }
    }
    return false;
}

//Increases snake length once it eats
bool Snake::shouldGrow(std::vector<taco*> &tacos, float x, float y) {
    
    for (int i = 0; i < tacos.size(); i++) {
        if (tacos[i]->contains(snake.front()->x, snake.front()->y)) {
            grow+=10;
            tacos.erase(tacos.begin() + i);
            bool neg = false;
            if(rand()%2 == 0) neg = true;
            
            tacos.push_back(new taco(x, y));
            return true;
        }
    }
    return false;
}
//Return true if head contains bumped someting
void Snake::collisionCheck() {
    float x = snake.front()->x;
    float y = snake.front()->y;
    if (x > 1.0 - girth || x < -1+girth || y > 0.83-girth || y < -1+girth) {
        alive = false;
    }
    int a = 0;
    for (std::list<Coord*>::iterator i = snake.begin(); i != snake.end(); ++i) {
        a++;
        if (a > 10) {
            if ((x > (*i)->x && x < (*i)->x + girth) && (y < (*i)->y && y > (*i)->y - girth)) {
                alive = false;
            }
        }
    }
    a = 0;
}
void Snake::vanish() {
    if (!alive && snake.size()>=1) {
        if (snake.size() > 5) {
            snake.pop_back();
            snake.pop_back();
            snake.pop_back();
            snake.pop_back();
        }else{
            snake.pop_back();
        }
    }
}
void Snake::draw() {
    list<Coord*>::reverse_iterator itr;
    bool alternateColor = true;
    
    for (itr = snake.rbegin(); itr != snake.rend(); ++itr) {
        if (itr == snake.rend()) {
            glColor3d(1.0, 0.0, 0.0);
        } else if (alternateColor) {
            glColor3d(0.0, 0.0, 0.0);
            alternateColor = false;
        } else {
            glColor3d(1.0, 1.0, 1.0);
            alternateColor = true;
        }
        glBegin(GL_POLYGON);
        glVertex2f((*itr)->x - girth/2, (*itr)->y + girth/2);//TL
        glVertex2f((*itr)->x + girth/2, (*itr)->y + girth/2);//TR
        glVertex2f((*itr)->x + girth/2, (*itr)->y - girth/2);//BR
        glVertex2f((*itr)->x - girth/2, (*itr)->y - girth/2);//BL
        glEnd();
    }
    
}
Coord* Snake::getHead() {
    return snake.front();
}
int Snake::length() {
    return (int)snake.size();
}
Snake::~Snake() {
    list<Coord*>::const_iterator itr;
    for (itr = snake.begin(); itr != snake.end(); ++itr) {
        delete *itr;
    }
}
