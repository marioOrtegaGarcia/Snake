//
//  Button.hpp
//  glutapp
//
//  Created by Mario Ortega on 5/7/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp

#include <stdio.h>
#include "TexRect.h"
class resetButton : public TexRect {
public:
    bool resetClicked;
    
    resetButton (const char* filename, float x, float y, float w, float h);
    bool checkResetClicked();
    bool contains(float mx, float my);
};

class pauseButton : public TexRect {
public:
    bool pauseClicked;
    pauseButton (const char* filename, float x, float y, float w, float h);
    bool checkPauseClicked();
    bool contains(float mx, float my);
};

#endif /* Button_hpp */
