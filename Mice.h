//
//  Mice.h
//  glutapp
//
//  Created by Mario Ortega on 5/7/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Mice_h
#define Mice_h

#include <stdio.h>
#include "TexRect.h"
class Mice {
    TexRect* mouse;
    float x;
    float y;
public:
    bool alive;
    Mice(float x= 0, float y=0);
    void kill();
    void draw();
    ~Mice();
};
#endif /* Mice_hpp */
