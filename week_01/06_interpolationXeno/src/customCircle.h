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
    void setup(ofVec2f _initPos);
    void update(ofVec2f _mouse);
    void draw();
    
private:
    ofVec2f currentPos;
    float pct;
    
};
