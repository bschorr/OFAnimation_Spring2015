//
//  Path.cpp
//  02_pathFollowing
//
//  Created by Bernardo Santos Schorr on 4/5/15.
//
//

#include "Path.h"


Path::Path() {
    // Arbitrary radius of 20
    radius = 20;
    start.set(0,ofGetHeight()*0.5);
    end.set(ofGetWidth(), start.y*1.2);
}

// Draw the path
void Path::draw() {
    ofSetColor(0,100);
    ofBeginShape();
        ofVertex(start.x, start.y-radius);
        ofVertex(end.x, end.y-radius);
        ofVertex(end.x, end.y+radius);
        ofVertex(start.x, start.y + radius);
    ofEndShape(true);
    
    ofSetColor(0);
    ofLine(start.x,start.y,end.x,end.y);
}