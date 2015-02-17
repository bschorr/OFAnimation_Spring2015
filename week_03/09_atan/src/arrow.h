//
//  arrow.h
//  09_atan
//
//  Created by Bernardo Santos Schorr on 2/17/15.
//
//

#pragma once

#include "ofMain.h"

class Arrow {
public:
    
    void setup();
    void update(float _x, float _y);
    void draw();
    
    ofVec2f pos;
    float rot;
    
};
