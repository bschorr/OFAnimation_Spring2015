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
    
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].resetForces();
        particleList[i].applyDampingForce(0.05);
        particleList[i].update();
    }
    
}

//--------------------------------------------------------------
void particleSystem::draw(){
    
    if (particleList.size() > 3) {
        for (int i = 2; i < particleList.size(); i++) {
            ofVec2f posOne = particleList[i].pos;
            ofVec2f posTwo = particleList[i-1].pos;
            ofVec2f posThree = particleList[i-2].pos;
            
            ofTriangle(posOne.x, posOne.y, posTwo.x, posTwo.y, posThree.x, posThree.y);
        }
    }
    
    
}

void particleSystem::mouseDragged(float x, float y) {
    ofVec2f vel;
    vel.x = ofRandom(-2,2);
    vel.y = ofRandom(-2,2);
    
    ofVec2f mouse;
    mouse.set(x, y);
    
    ofVec2f offset;
    offset.x = ofRandom(-30, 30);
    offset.y = ofRandom(-30, 30);
    
    Particle p(mouse+offset, vel);
    particleList.push_back(p);
    
}