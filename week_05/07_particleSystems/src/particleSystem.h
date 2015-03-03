//
//  particleSystem.h
//  01_manyParticles
//
//  Created by Bernardo Schorr on 3/2/15.
//
//

#pragma once

#include "ofMain.h"
#include "Particle.h"

class particleSystem {
public:
    
    particleSystem(ofVec2f _pos);
    void update(ofVec2f _force);
    void draw();
    
    vector<Particle> particleList;
    ofVec2f pos;
    
};
