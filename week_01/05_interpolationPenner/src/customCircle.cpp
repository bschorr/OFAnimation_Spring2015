//
//  customCircle.cpp
//  01_simpleClass
//
//  Created by Bernardo Santos Schorr on 1/31/15.
//
//

#include "customCircle.h"

customCircle::customCircle() {
    
}

void customCircle::setup(ofVec2f _initPos) {
    initPos = _initPos;
    currentPos = initPos;
}

void customCircle::update() {
    
    if(currentIter < totalIter) {
     
        pct = easeOut(currentIter, 0.0, 1.0, totalIter);
        currentPos.x = initPos.x * (1 - pct) + finalPos.x * pct;
        
        pct = easeIn(currentIter, 0.0, 1.0, totalIter);
        currentPos.y = initPos.y * (1 - pct) + finalPos.y * pct;
        
        currentIter++;
        
    }
    
    
}

void customCircle::draw() {
    
    //ofLine (initPos, finalPos);
    ofCircle(currentPos, 10);

    ofDrawBitmapString("Click anywhere!", 30, 30);
    ofDrawBitmapString("Init Pos", initPos);
    ofDrawBitmapString("Final Pos", finalPos);
    
}

void customCircle::setPenner(ofVec2f _newPos, int _totalIter){
    currentIter = 0;
    totalIter = _totalIter;
    initPos = currentPos;
    finalPos = _newPos;
}

//this code is using Penner's BACK functions for easing. Check out the other ones he made!

float customCircle::easeIn (float t,float b , float c, float d) {
    float s = 1.70158f;
    float postFix = t/=d;
    return c*(postFix)*t*((s+1)*t - s) + b;
}
float customCircle::easeOut(float t,float b , float c, float d) {
    float s = 1.70158f;
    return c*((t=t/d-1)*t*((s+1)*t + s) + 1) + b;
}

float customCircle::easeInOut(float t,float b , float c, float d) {
    float s = 1.70158f;
    if ((t/=d/2) < 1) return c/2*(t*t*(((s*=(1.525f))+1)*t - s)) + b;
    float postFix = t-=2;
    return c/2*((postFix)*t*(((s*=(1.525f))+1)*t + s) + 2) + b;
}