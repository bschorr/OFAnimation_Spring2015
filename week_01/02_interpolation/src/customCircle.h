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
    void setup(ofVec2f _initPos, ofVec2f _finalPos);
    void update(float pct);
    void draw();
    
private:
    ofVec2f initPos, finalPos, currentPos;
    float pct;
    
};
