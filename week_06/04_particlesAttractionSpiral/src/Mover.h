//
//  Mover.h
//  04_moverClass
//
//  Created by Bernardo Schorr on 2/20/15.
//
//

#pragma once

#include "ofMain.h"

class Mover {
public:
    
    void setup(float x, float y, float _mass);
    void update();
    void resetForces();
    void applyForce(ofVec2f force);
    void applyElastic();
    void applyDampingForce(float damping);
    void checkEdges();
    void draw();
    
    ofVec2f origPos, pos, vel, acc;
    float mass;
    
};