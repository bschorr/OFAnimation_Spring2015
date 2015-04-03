//
//  Vehicle.cpp
//  01_steer
//
//  Created by Bernardo Santos Schorr on 3/31/15.
//
//

#include "Vehicle.h"


void Vehicle::setup() {
    pos = ofGetWindowSize()*0.5;
    vel.set(5.0, 5.0);
    acc.set(0.0, 0.0);
    
    maxSpeed = 10.0;
    maxForce = 0.25;
    mass = 1.0;
}

void Vehicle::update() {
    vel += acc;
    vel.limit(maxSpeed);
    pos += vel;
    
}

void Vehicle::resetForces() {
    acc *= 0;
}

void Vehicle::applyForce(ofVec2f force) {
    acc += force/mass;
}

void Vehicle::draw() {
    
    ofPushMatrix();
    ofTranslate(pos);
    float rot = atan2( vel.y, vel.x );
    ofRotate(ofRadToDeg(rot));
    
    ofSetColor(255);
    ofTriangle(0, 10, 0, -10, 40, 0);
    ofPopMatrix();
}

void Vehicle::avoidWalls(float d) {
    
    ofVec2f desired;
    desired.set(0, 0);
    
    if (pos.x < d) {
        desired.set(maxSpeed, vel.y);
    }
    else if (pos.x > ofGetWidth()-d) {
        desired.set(-maxSpeed, vel.y);
    }
    
    if (pos.y < d) {
        desired.set(vel.x, maxSpeed);
    }
    else if (pos.y > ofGetHeight()-d) {
        desired.set(vel.x, -maxSpeed);
    }
    
    
    
    if (desired.length() != 0.0) {
        desired.normalize();
        desired *= maxSpeed;
        ofVec2f steer = desired - vel;
        steer.limit(maxForce);
        applyForce(steer);
    }
    
}