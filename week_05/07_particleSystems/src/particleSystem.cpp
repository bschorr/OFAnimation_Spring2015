//
//  particleSystem.cpp
//  01_manyParticles
//
//  Created by Bernardo Schorr on 3/2/15.
//
//

#include "particleSystem.h"

particleSystem::particleSystem(ofVec2f _pos){
    pos = _pos;
}

//--------------------------------------------------------------
void particleSystem::update(ofVec2f _force){
    
    for (int i = 0; i < 10; i++) {
        Particle particle(pos);
        particleList.push_back(particle);
        
    }
    
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].resetForces();
        particleList[i].applyForce(_force);
        particleList[i].update();
    }
    
    while (particleList.size() > 1000) {
        particleList.erase(particleList.begin());
    }
    
}

//--------------------------------------------------------------
void particleSystem::draw(){
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].draw();
    }
    
}