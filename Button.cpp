//
//  Button.cpp
//  glutapp
//
//  Created by Mario Ortega on 5/7/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "Button.h"
resetButton::resetButton (const char* filename, float x, float y, float w, float h) : TexRect (filename, x, y, w, h){
    resetClicked = false;
}
bool resetButton::checkResetClicked() {
    return resetClicked;
}

bool resetButton::contains(float mx, float my) {
    //return TexRect::contains(mx, my);
    return mx >= -1 && mx <= -1 + 0.167 && my <= 1 && my >= 1 - 0.167;
}

pauseButton::pauseButton (const char* filename, float x, float y, float w, float h) : TexRect (filename, x, y, w, h){
    pauseClicked = false;
}

bool pauseButton::checkPauseClicked() {
    return pauseClicked;
}

bool pauseButton::contains(float mx, float my){
    return mx >= 0.83 && mx <= 0.83 + 0.167 && my <= 1 && my >= 1 - 0.167;
}
