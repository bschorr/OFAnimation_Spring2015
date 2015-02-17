//
//  arrow.cpp
//  09_atan
//
//  Created by Bernardo Santos Schorr on 2/17/15.
//
//

#include "arrow.h"

void Arrow::setup() {
    
    pos.set(0);

}

void Arrow::update(float _x, float _y) {
    
    ofVec2f newPos;
    newPos.set(_x, _y);
    pos = pos * 0.97 + newPos * 0.03;
    
    ofVec2f diff;
    diff = newPos - pos;
    rot = atan2(diff.y, diff.x);
    rot = ofRadToDeg(rot);
}

void Arrow::draw() {
    
    float x1 = 0;
    float y1 = -10;
    
    float x2 = 0;
    float y2 = 10;
    
    float x3 = 30;
    float y3 = 0;
    
    ofTranslate(pos);
    ofRotate(rot);
    ofTriangle (x1, y1, x2, y2, x3, y3);
    
}