//
//  customCircle.cpp
//  01_vectorXeno
//
//  Created by Bernardo Santos Schorr on 2/8/15.
//
//

#include "customCircle.h"

void customCircle::setup() {
    
    pos.set(0, 0);
    
}

void customCircle::update(ofVec2f _pos) {
    
    pos = pos * 0.9 + _pos * 0.1;
    
}

void customCircle::draw() {
    
    ofCircle(pos, 10);
    
}
