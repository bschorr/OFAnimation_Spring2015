//
//  Particle.cpp
//  03_particle_particle
//
//  Created by Bernardo Santos Schorr on 4/6/15.
//
//

#include "Particle.h"

Particle::Particle() {
    pos.set(ofRandomWidth(), ofRandomHeight());
}

void Particle::setup() {
    
}

void Particle::update() {
    vel += acc;
    pos += vel;
    
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

void Particle::applyAttraction(Particle &p, float radius, float scale) {
    
    ofVec2f diff	= pos - p.pos;
    float length	= diff.length();
    
    if (length < radius){
        float pct = 1 - (length / radius);
        diff.normalize();
        ofVec2f force = diff * scale * pct;
        applyForce(force * -1);
        p.applyForce(force);
    }
    
}

void Particle::applyRepulsion(Particle &p, float radius, float scale) {
    
    ofVec2f diff	= pos - p.pos;
    float length	= diff.length();
    
    if (length < radius){
        float pct = 1 - (length / radius);
        diff.normalize();
        ofVec2f force = diff * scale * pct;
        applyForce(force);
        p.applyForce(force * -1);
    }
    
}

void Particle::applyRepulsion(ofVec2f _pos, float radius, float scale) {
    
    ofVec2f diff	= pos - _pos;
    float length	= diff.length();
    
    if (length < radius){
        float pct = 1 - (length / radius);
        diff.normalize();
        ofVec2f force = diff * scale * pct;
        applyForce(force);
    }
    
}

void Particle::draw() {
    ofCircle(pos, 3);
}