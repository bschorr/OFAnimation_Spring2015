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
    void update();
    void draw();
    void setPenner(ofVec2f _newPos, int _totalIter);
    
    float easeIn (float t,float b , float c, float d);
    float easeOut (float t,float b , float c, float d);
    float easeInOut (float t,float b , float c, float d);
    
    //t == currentIteration
    //b == startValue
    //c == changeInValue
    //d == totalIterations
    
private:
    int currentIter, totalIter;
    float pct;
    float posX, posY;
    ofVec2f initPos, finalPos, currentPos;
    
};
