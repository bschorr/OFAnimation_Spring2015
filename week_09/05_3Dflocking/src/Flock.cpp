//
//  Flock.cpp
//  04_flocking
//
//  Created by Bernardo Santos Schorr on 4/6/15.
//
//

#include "Flock.h"


Flock::Flock() {
    target.set(0, 0, 0);
}

void Flock::update() {
    
    float noiseX = ofNoise(ofGetElapsedTimef()*0.1);
    float noiseY = ofNoise((ofGetElapsedTimef()+1000)*0.1);
    float noiseZ = ofNoise((ofGetElapsedTimef()+10000)*0.1);
    
    target.x = ofMap(noiseX, 0, 1, -200, 200);
    target.y = ofMap(noiseY, 0, 1, -200, 200);
    target.z = ofMap(noiseZ, 0, 1, -200, 200);
    
    for( vector<Boid>::iterator b=boids.begin(); b!=boids.end(); b++){
        b->resetForces();
        b->flock(boids, target);
        b->update();
    }
}

void Flock::draw() {
    
    ofSetColor(255, 0, 0);
    ofDrawBox(target, 20);
    
    ofSetColor(255);
    for (vector<Boid>::iterator b=boids.begin(); b!=boids.end(); b++) {
        b->draw();
    }
}

void Flock::addBoid(Boid b) {
    boids.push_back(b);
}