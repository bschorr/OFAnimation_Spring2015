//
//  customCircle.h
//  01_simpleClass
//
//  Created by Bernardo Santos Schorr on 1/31/15.
//
//

#pragma once

#include "ofMain.h"

class customCircle {
public:
    customCircle();
    void setup(float _posX, float _posY);
    void update();
    void draw();
    
private:
    float posX, posY;
    
};
