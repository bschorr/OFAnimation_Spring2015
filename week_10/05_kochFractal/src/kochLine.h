//
//  kochLine.h
//  05_kochFractal
//
//  Created by Bernardo Schorr on 4/26/15.
//
//

#pragma once
#include "ofMain.h"

class kochLine {
public:
    
    kochLine(ofVec2f start, ofVec2f end);
    void draw();
    ofVec2f start();
    ofVec2f end();
    ofVec2f kochLeft();
    ofVec2f kochMiddle();
    ofVec2f kochRight();
    void rotate(ofVec2f &v, float theta);
    
    ofVec2f a, b;
    
};
