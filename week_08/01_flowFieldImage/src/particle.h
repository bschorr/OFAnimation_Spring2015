//
//  Particle.h
//  03_flowField
//
//  Created by Bernardo Santos Schorr on 3/31/15.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    
    void setup();
    
    void resetForces();
    void applyForce(ofVec2f force);
    void applyDampingForce(float damping);
    
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
    
};
