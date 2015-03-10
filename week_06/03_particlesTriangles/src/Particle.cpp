//
//  Particle.cpp
//  01_oneParticle
//
//  Created by Bernardo Schorr on 3/2/15.
//
//

#include "Particle.h"

Particle::Particle(ofVec2f _pos, ofVec2f _vel) {
    pos.set(_pos);
    vel.set(_vel);
    //vel.x = ofRandom(-2, 2);
    //vel.y = ofRandom(-1, -5);
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
    acc -= vel * damping;
}

void Particle::update() {
    vel += acc;
    pos += vel;
    
}

void Particle::draw(ofColor _color) {
    ofSetColor(_color);
}



