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

void customCircle::setup(ofVec2f _initPos, ofVec2f _finalPos) {
    initPos = _initPos;
    finalPos = _finalPos;
}

void customCircle::linear(float _pct) {
    
    pct = _pct;
    currentPos = initPos * (1 - pct) + finalPos * pct;
    
}

void customCircle::easeOut(float _pct) {
    
    pct = _pct * (2-_pct);
    currentPos = initPos * (1 - pct) + finalPos * pct;
    
}

void customCircle::easeIn(float _pct) {
    
    pct = powf(_pct, 2); //== _pct * pct
    currentPos = initPos * (1 - pct) + finalPos * pct;
    
}

void customCircle::draw() {
    
    ofLine (initPos, finalPos);
    ofCircle(currentPos, 10);
    
    //all of this is just writing to the screen.
    ofDrawBitmapString("Init Pos", initPos.x, initPos.y-30);
    ofDrawBitmapString("Final Pos", finalPos.x, finalPos.y-30);
    ofDrawBitmapString("pct = " + ofToString(pct), currentPos.x, currentPos.y - 20);
    
}