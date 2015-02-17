//
//  customCircle.h
//  04_manySines
//
//  Created by Bernardo Santos Schorr on 2/16/15.
//
//

#pragma once

#include "ofMain.h"

class customCircle {
public:
    
    void setup(float _offset);
    void update();
    void draw();
    
    float offset;
    float size;
    float lineWidth;
};
