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
    
    choice = ofRandom(4);
    if (choice == 0) pos.x ++;
    if (choice == 1) pos.y ++;
    if (choice == 2) pos.x --;
    if (choice == 3) pos.y --;
    
}

void customCircle::draw() {
    
    ofRect(pos, 1, 1);
    
}
