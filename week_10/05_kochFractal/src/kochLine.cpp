//
//  kochLine.cpp
//  05_kochFractal
//
//  Created by Bernardo Schorr on 4/26/15.
//
//  Based of:
//  Koch Curve
//  Daniel Shiffman <http://www.shiffman.net>
//  Nature of Code, Chapter 8
//

#include "kochLine.h"


kochLine::kochLine(ofVec2f start, ofVec2f end) {
    a = start;
    b = end;
}

void kochLine::draw() {
    ofLine(a, b);
}

ofVec2f kochLine::start() {
    ofVec2f start = a;
    return start;
}

ofVec2f kochLine::kochLeft() {
    ofVec2f v = b - a;
    v /= 3;
    v += a;
    return v;
}

ofVec2f kochLine::kochMiddle() {
    ofVec2f v = b - a;
    v /= 3;
    
    v.rotate(-60);
    
    ofVec2f p = kochLeft();
    v += p;
    
    return v;
}

ofVec2f kochLine::kochRight() {
    ofVec2f v = a - b;
    v /= 3;
    v += b;
    return v;
}

ofVec2f kochLine::end() {
    ofVec2f end = b;
    return end;
}