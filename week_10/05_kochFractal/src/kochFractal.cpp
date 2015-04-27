//
//  kochFractal.cpp
//  05_kochFractal
//
//  Created by Bernardo Schorr on 4/26/15.
//
//

#include "kochFractal.h"

// Koch Curve
// Daniel Shiffman <http://www.shiffman.net>
// Nature of Code, Chapter 8

// A class to manage the list of line segments in the snowflake pattern

kochFractal::kochFractal() {
    start = ofVec2f(0, ofGetHeight()-20);
    end = ofVec2f(ofGetWidth(),ofGetHeight()-20);
    restart();
}

void kochFractal::nextLevel() {
    // For every line that is in the arraylist
    // create 4 more lines in a new arraylist
    lines = iterate(lines);
    count++;
}

void kochFractal::restart() {
    count = 0;      // Reset count
    lines.clear();  // Empty the vector
    lines.push_back(kochLine(start,end));  // Add the initial line (from one end PVector to the other)
}

int kochFractal::getCount() {
    return count;
}

// This is easy, just draw all the lines
void kochFractal::render() {
    for( vector<kochLine>::iterator l=lines.begin(); l!=lines.end(); l++){
        l->draw();
    }
}

// This is where the **MAGIC** happens
// Step 1: Create an empty arraylist
// Step 2: For every line currently in the arraylist
//   - calculate 4 line segments based on Koch algorithm
//   - add all 4 line segments into the new arraylist
// Step 3: Return the new arraylist and it becomes the list of line segments for the structure

// As we do this over and over again, each line gets broken into 4 lines, which gets broken into 4 lines, and so on. . .
vector<kochLine> kochFractal::iterate(vector<kochLine> before) {
    vector<kochLine> now;    // Create emtpy list
    for( vector<kochLine>::iterator l=before.begin(); l!=before.end(); l++){
        // Calculate 5 koch PVectors (done for us by the line object)
        ofVec2f a = l->start();
        ofVec2f b = l->kochLeft();
        ofVec2f c = l->kochMiddle();
        ofVec2f d = l->kochRight();
        ofVec2f e = l->end();
        // Make line segments between all the PVectors and add them
        now.push_back(kochLine(a,b));
        now.push_back(kochLine(b,c));
        now.push_back(kochLine(c,d));
        now.push_back(kochLine(d,e));
    }
    return now;
}