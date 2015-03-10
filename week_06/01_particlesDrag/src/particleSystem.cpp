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
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
}

//--------------------------------------------------------------
void particleSystem::update(ofVec2f _force){
    
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].resetForces();
        particleList[i].update();
    }
    
}

//--------------------------------------------------------------
void particleSystem::draw(){
    ofSetColor(color);
    
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].draw(color);
    }
    
}

void particleSystem::mouseDragged(float x, float y) {
    Particle p(ofVec2f(x, y));
    particleList.push_back(p);
}