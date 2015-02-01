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

void customCircle::setup(float _posX, float _posY) {
    posX = _posX;
    posY = _posY;
}

void customCircle::update() {
    
    posX++;
    
}

void customCircle::draw() {
    
    ofCircle(posX, posY, 10);
    
}