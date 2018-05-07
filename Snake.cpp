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
    snake.push_front(new Coord(0,0));
    grow = down = left = right = false;
    alive = up = true;
    
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
void Snake::move() {
    Coord* head = new Coord(snake.front()->x,snake.front()->y);
    if (up) head->moveUp();
    if (down) head->moveDown();
    if (left) head->moveLeft();
    if (right) head->moveRight();
    snake.push_front(head);
    if (!grow) snake.pop_back();
}
//Increases snake length once it eats
void Snake::shouldGrow() {
    if (/* DISABLES CODE */ (false)) grow = true;
}

//Return true if head contains bumped someting
bool Snake::collisionCheck() {
    return false;
}
void Snake::draw() {
     list<Coord*>::iterator itr;
     float width = 2.0/40, height = 1.83/40;
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
             } else {
                 glColor3d(0.0, 0.0, 0.0);
             }
             alternateColor !=alternateColor;
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
