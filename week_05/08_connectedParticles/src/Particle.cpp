//
//  Particle.cpp
//  01_oneParticle
//
//  Created by Bernardo Schorr on 3/2/15.
//
//

#include "Particle.h"

Particle::Particle(ofVec2f _pos, ofVec2f _vel) {
    vel = _vel;
    pos = _pos;
    lifespan = 255;
}

void Particle::resetForces() {
    acc *= 0;
}

void Particle::applyForce(ofVec2f force) {
    acc += force;
}

void Particle::update() {
    vel += acc;
    pos += vel;
    
    if (lifespan > 0) lifespan -= 1.0;
    
}

void Particle::draw() {
    ofSetColor(lifespan);
    ofCircle(pos, 5);
}



