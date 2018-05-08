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

static App* singleton;

class ExplosionBruh {
    
public:
    
    void explode(int x){
        
        if(singleton->game_over == true){
           singleton->gameOver->animate();
        }
    }
    
           };
    
    

#endif /* Explosion_h */
