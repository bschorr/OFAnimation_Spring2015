//
//  customCircle.cpp
//  04_manySines
//
//  Created by Bernardo Santos Schorr on 2/16/15.
//
//

#include "customCircle.h"

void customCircle::setup(float _offset) {
    
    offset = _offset;
    
}

void customCircle::update() {
    
    float sinOfTime = sin(ofGetElapsedTimef()+offset);
    size = ofMap(sinOfTime, -1, 1, 50, 300);
    lineWidth = ofMap(sinOfTime, -1, 1, 0.1, 6);
    
    
}

void customCircle::draw() {
    
    ofSetLineWidth(lineWidth);
    ofCircle(ofGetWindowSize()/2, size);
    
}