//
//  Particle.h
//  03_particle_particle
//
//  Created by Bernardo Santos Schorr on 4/6/15.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    
    Particle();
    
    void setup();
    
    void resetForces();
    void applyForce(ofVec2f force);
    void applyDampingForce(float damping);
    

    void applyAttraction(Particle &p, float radius, float scale);
    void applyRepulsion(Particle &p, float radius, float scale);
    void applyRepulsion(ofVec2f _pos, float radius, float scale);
    
    
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
    
};
