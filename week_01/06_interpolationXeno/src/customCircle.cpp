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
    currentPos = _initPos;
}

void customCircle::update(ofVec2f _mouse) {
    
    pct = 0.05;
    currentPos = currentPos * (1 - pct) + _mouse * pct;
    
}

void customCircle::draw() {
    
    ofCircle(currentPos, 10);
    ofDrawBitmapString("Move your mouse around.", 30, 30);
}