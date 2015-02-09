//
//  customCircle.h
//  01_vectorXeno
//
//  Created by Bernardo Santos Schorr on 2/8/15.
//
//

#pragma once

#include "ofMain.h"

class customCircle {
public:
    
    void setup();
    void update(ofVec2f _pos);
    void draw();
    
    ofVec2f pos;
    
};
