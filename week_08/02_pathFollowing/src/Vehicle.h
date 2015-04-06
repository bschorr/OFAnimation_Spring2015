//
//  Vehicle.h
//  02_pathFollowing
//
//  Created by Bernardo Santos Schorr on 4/5/15.
//
//

#pragma once
#include "ofMain.h"
#include "Path.h"

class Vehicle {
public:
    
    void setup(ofVec2f p, float ms, float mf, bool * _debug);
    void update();
    void draw();
    
    void resetForces();
    void applyForce(ofVec2f force);
    void seek (ofVec2f target);
    
    // This function implements Craig Reynolds' path following algorithm
    // http://www.red3d.com/cwr/steer/PathFollow.html
    // porting from Daniel Shiffman's Nature of Code book
    void follow(Path p);
    ofVec2f getNormalPoint(ofVec2f p, ofVec2f a, ofVec2f b);
    
    ofVec2f pos, vel, acc;
    
    float maxSpeed, maxForce;
    
    float r;
    bool * debug;
    
};
