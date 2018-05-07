//
//  Snake.cpp
//  glutapp
//
//  Created by Mario Ortega on 5/6/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "Snake.h"
#include <iostream>

//Creates the snake at the Center
Snake::Snake() {
    girth = 2.0/40;
    //snake.push_front(new Coord(0.0,0.0-(girth*4.0)));
    snake.push_front(new Coord(0.0,(0.0-(girth*2.0))));
    snake.push_front(new Coord(0.0,0.0));
    grow = down = left = right = false;
    alive = true;
    up = false;
    //alive = up = true;
}
//Changes Bool Valuse for Directions
void Snake::changeDirection(int key) {
    switch (key) {
        case 100:
            if (!right) {
                std::cout << "left" << std::endl;
                left = true;
                up = down = right = false;
            }
            break;
        case 101:
            if (!down) {
                std::cout << "up" << std::endl;
                up = true;
                left = right = down = false;
            }
            break;
        case 102:
            if (!left) {
                std::cout << "right" << std::endl;
                right = true;
                up = down = left = false;
            }
            break;
        case 103:
            if (!up) {
                std::cout << "down" << std::endl;
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
    //std::cout << "(" << snake.front()->x << "," << snake.front()->y << ")" << std::endl;
    if (up) head->moveUp(step);
    if (down) head->moveDown(step);
    if (left) head->moveLeft(step);
    if (right) head->moveRight(step);
    snake.push_front(head);
    shouldGrow();
    if (!grow) snake.pop_back();
}
//Increases snake length once it eats
void Snake::shouldGrow() {
    
    if ( (false)) grow = true;
}

//Return true if head contains bumped someting
void Snake::collisionCheck() {
    float x = snake.front()->x;
    float y = snake.front()->y;
    if (x > 1.0 - girth || x < -1+girth || y > 1.83-girth || y < -1+girth) {
        std::cout << "~";
        alive = false;
    }
}

void Snake::draw() {
    list<Coord*>::iterator itr;
    float width = girth, height = girth;
    bool alternateColor = true;
    for (itr = snake.begin(); itr != snake.end(); ++itr) {
        if (itr == snake.begin()) {
            glColor3d(0.0, 1.0, 0.0);
            glBegin(GL_POLYGON);
            glVertex2f((*itr)->x - width/2, (*itr)->y + height/2);//TL
            glVertex2f((*itr)->x + width/2, (*itr)->y + height/2);//TR
            glVertex2f((*itr)->x + width/2, (*itr)->y - height/2);//BR
            glVertex2f((*itr)->x - width/2, (*itr)->y - height/2);//BL
            glEnd();
        } else {
            if (alternateColor) {
                glColor3d(1.0, 1.0, 1.0);
                alternateColor = false;
            } else {
                glColor3d(0.0, 0.0, 0.0);
                alternateColor = true;
            }
            glBegin(GL_POLYGON);
            glVertex2f((*itr)->x - width/2, (*itr)->y + height/2);//TL
            glVertex2f((*itr)->x + width/2, (*itr)->y + height/2);//TR
            glVertex2f((*itr)->x + width/2, (*itr)->y - height/2);//BR
            glVertex2f((*itr)->x - width/2, (*itr)->y - height/2);//BL
            glEnd();
        }
    }
}

Snake::~Snake() {
    list<Coord*>::const_iterator itr;
    for (itr = snake.begin(); itr != snake.end(); ++itr) {
        delete *itr;
    }
}
