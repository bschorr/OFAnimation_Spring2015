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
        particleList[i].applyDampingForce(0.2);
        particleList[i].update();
    }
    
}

//--------------------------------------------------------------
void particleSystem::draw(){
    ofSetColor(color);
    
    ofBeginShape();
    
    for (int i = 0; i < particleList.size(); i++) {
        ofVertex(particleList[i].pos.x, particleList[i].pos.y);
    }
    
    ofEndShape();
    
}

void particleSystem::mouseDragged(float x, float y) {
    ofVec2f vel;
    vel.x = x - ofGetPreviousMouseX();
    vel.y = y - ofGetPreviousMouseY();
    
    Particle p(ofVec2f(x, y), vel);
    particleList.push_back(p);
}