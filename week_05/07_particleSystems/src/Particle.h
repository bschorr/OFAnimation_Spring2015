//
//  Particle.h
//  01_oneParticle
//
//  Created by Bernardo Schorr on 3/2/15.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    
    Particle(ofVec2f _pos);
    
    void setup();
    
    void resetForces();
    void applyForce(ofVec2f force);
    
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
    float lifespan;
    
};
