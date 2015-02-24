//
//  Mover.cpp
//  04_moverClass
//
//  Created by Bernardo Schorr on 2/20/15.
//
//

#include "Mover.h"

void Mover::setup(float x, float y, float _mass) {
    pos.set(x, y);
    mass = _mass;
}

void Mover::resetForces() {
    acc *= 0;
}

void Mover::applyForce(ofVec2f force) {
    //force = mass * acc
    acc += force/mass;
}

void Mover::applyDampingForce(float damping) {
    acc -= vel.getNormalized() * damping;
}

void Mover::update() {
    vel += acc;
    pos += vel;
}

void Mover::checkEdges() {
    if (pos.x < 0) {
        pos.x = 0;
        vel.x *= -1;
    }
    
    if (pos.x > ofGetWidth()) {
        pos.x = ofGetWidth();
        vel.x *= -1;
    }
    
    if (pos.y < 0) {
        pos.y = 0;
        vel.y *= -1;
    }
    
    if (pos.y > ofGetHeight()) {
        pos.y = ofGetHeight();
        vel.y *= -1;
    }
}

void Mover::draw() {
    ofCircle(pos, 10 * mass);
}