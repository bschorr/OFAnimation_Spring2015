//
//  kochFractal.cpp
//  05_kochFractal
//
//  Created by Bernardo Schorr on 4/26/15.
//
//  Based of:
//  Koch Curve
//  Daniel Shiffman <http://www.shiffman.net>
//  Nature of Code, Chapter 8
//

#include "kochFractal.h"

kochFractal::kochFractal() {
    start = ofVec2f(0, ofGetHeight()-20);
    end = ofVec2f(ofGetWidth(),ofGetHeight()-20);
    restart();
}

void kochFractal::nextLevel() {

    lines = iterate(lines);
    count++;
}

void kochFractal::restart() {
    count = 0; // reset the count
    lines.clear();  // Empty the vector
    lines.push_back(kochLine(start, end));  // Add the initial line
}

int kochFractal::getCount() {
    return count;
}

// This is easy, just draw all the lines
void kochFractal::draw() {
    for( vector<kochLine>::iterator l=lines.begin(); l!=lines.end(); l++){
        l->draw();
    }
}

// MAGIC
vector<kochLine> kochFractal::iterate(vector<kochLine> before) {
    
    vector<kochLine> now;    // Create emtpy vector
    
    for( vector<kochLine>::iterator l=before.begin(); l!=before.end(); l++){
        
        // Calculate 5 koch points for each line
        ofVec2f a = l->start();
        ofVec2f b = l->kochLeft();
        ofVec2f c = l->kochMiddle();
        ofVec2f d = l->kochRight();
        ofVec2f e = l->end();
        
        // Make line segments between all the points
        now.push_back(kochLine(a,b));
        now.push_back(kochLine(b,c));
        now.push_back(kochLine(c,d));
        now.push_back(kochLine(d,e));
    }
    return now;
}