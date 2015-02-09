//
//  customCircle.cpp
//  03_randomWalker
//
//  Created by Bernardo Santos Schorr on 2/8/15.
//
//

#include "customCircle.h"

void customCircle::setup() {
    
    pos.set(ofGetWindowSize()/2);
    
}

void customCircle::update() {
    
    choice = ofRandom(10);
    if (choice < 4) pos.x ++;
    if (choice > 4 && choice < 6) pos.y ++;
    if (choice > 6 && choice < 8) pos.x --;
    if (choice > 8 && choice < 10) pos.y --;
    
}

void customCircle::draw() {
    
    ofRect(pos, 1, 1);
    
}
