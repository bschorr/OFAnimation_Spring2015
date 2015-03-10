//
//  particleSystem.cpp
//  01_manyParticles
//
//  Created by Bernardo Schorr on 3/2/15.
//
//

#include "particleSystem.h"

particleSystem::particleSystem(){
    sprite.loadImage("sprite.png");
    timeOffset = ofRandom(100000);
    yOffset = 1000;
}

//--------------------------------------------------------------
void particleSystem::update(ofVec2f _force){
    
    float noiseX = ofNoise(ofGetElapsedTimef()+timeOffset);
    float noiseY = ofNoise(ofGetElapsedTimef()+timeOffset+yOffset);
    
    pos.x = ofMap(noiseX, 0, 1, 0, ofGetWidth());
    pos.y = ofMap(noiseY, 0, 1, 0, ofGetHeight());
    
    
    for (int i = 0; i < 10; i++) {
        Particle particle(pos);
        particleList.push_back(particle);
        
    }
    
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].resetForces();
        //particleList[i].applyForce(_force);
        particleList[i].update();
    }
    
    while (particleList.size() > 200) {
        particleList.erase(particleList.begin());
    }
    
}

//--------------------------------------------------------------
void particleSystem::draw(){
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].draw(sprite);
    }
    
}