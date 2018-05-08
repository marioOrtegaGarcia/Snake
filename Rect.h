//
//  Rect.h
//  glutapp
//
//  Created by Mario Ortega on 5/7/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Rect_h
#define Rect_h

#include <stdio.h>
struct Rect{
    float x, y, width, height;
    bool pressed = false;
    Rect(float a, float b, float c, float d);
    float getX();
    float getY();
    float getWidth();
    float getHeight();
    void setX(float input);
    void setY(float input);
    void setWidth(float input);
    void setHeight(float input);
    void click();
    void unClick();
    bool contains(float inputX, float inputY);
    ~Rect();
};
#endif /* Rect_h */
