//
//  kochLine.cpp
//  05_kochFractal
//
//  Created by Bernardo Schorr on 4/26/15.
//
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

ofVec2f kochLine::end() {
    ofVec2f end = b;
    return end;
}

// This is easy, just 1/3 of the way
ofVec2f kochLine::kochLeft() {
    ofVec2f v = b - a;
    v /= 3;
    v += a;
    return v;
}

// More complicated, have to use a little trig to figure out where this PVector is!
ofVec2f kochLine::kochMiddle() {
    ofVec2f v = b - a;
    v /= 3;
    
    ofVec2f p = a;
    p += v;
    
    rotate(v, -ofDegToRad(60));
    p += v;
    
    return p;
}


// Easy, just 2/3 of the way
ofVec2f kochLine::kochRight() {
    ofVec2f v = a - b;
    v /= 3;
    v += b;
    return v;
}

void kochLine::rotate(ofVec2f &v, float theta) {
    float xTemp = v.x;
    // Might need to check for rounding errors like with angleBetween function?
    v.x = v.x*cos(theta) - v.y*sin(theta);
    v.y = xTemp*sin(theta) + v.y*cos(theta);
}