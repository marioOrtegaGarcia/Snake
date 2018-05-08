//
//  Explosion.h
//  glutapp
//
//  Created by Erik Aguilar on 5/7/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Explosion_h
#define Explosion_h

#include "App.h"
#include <stdio.h>
#include <string>

using namespace std;

class ExplosionBruh {
    
public:
    
    void explode(int x){
        
        if(!doubleton->current->explosion->done()){
            doubleton->current->explosion->advance();
            doubleton->redraw();
            glutTimerFunc(32, explode, x);
        }
    }
    
    explosion = new MoveImg("explode.bmp", 5, 5, x, y, 0.5, 0.5);

};
#endif /* Explosion_h */
