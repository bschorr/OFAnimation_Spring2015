//
//  Particle.cpp
//  01_oneParticle
//
//  Created by Bernardo Schorr on 3/2/15.
//
//

#include "Particle.h"

Particle::Particle(ofVec2f _pos) {
    pos.set(_pos);
    vel.x = ofRandom(-2, 2);
    vel.y = ofRandom(-1, -5);
    lifespan = ofRandom(155, 255);
    size = ofRandom(5, 20);
}

void Particle::setup() {
    
}

void Particle::resetForces() {
    acc *= 0;
}

void Particle::applyForce(ofVec2f force) {
    acc += force;
}

void Particle::applyDampingForce(float damping) {
    acc -= vel.getNormalized() * damping;
}

void Particle::update() {
    vel += acc;
    pos += vel;
    
    if (lifespan > 0) lifespan -= 3.0;
    
}

void Particle::draw(ofColor _color) {
    ofSetColor(_color, lifespan);
    ofCircle(pos, size);
}



