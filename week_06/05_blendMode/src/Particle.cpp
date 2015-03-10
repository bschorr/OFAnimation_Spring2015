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
    vel.y = ofRandom(-2, 2);
    lifespan = 255;
    color.set(255, 0, 0);
}

void Particle::setup() {
    
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
    
    color.g = lifespan;
    color.b = lifespan;
    
    
    if (lifespan > 0) lifespan -= 10.0;
    
}

void Particle::draw(ofImage &img) {
    ofSetColor(color, lifespan);
    img.draw(pos, lifespan*0.25, lifespan*0.25);
    //ofCircle(pos, 5);
}



