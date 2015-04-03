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
    vel.set(0.0, 0.0);
    acc.set(0.0, 0.0);
    
    maxSpeed = 4.0;
    maxForce = 0.1;
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
    acc += force;
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

void Vehicle::seek(ofVec2f target) {
    ofVec2f desired = target - pos;
    
    float d = desired.length();
    desired.normalize();
    
    //for arriving smoothly
    if (d < 100) {
        float m = ofMap(d,0,100,0,maxSpeed);
        desired *= m;
    } else {
        desired *= maxSpeed;
    }
    
    ofVec2f steer = desired - vel;
    steer.limit(maxForce);
    applyForce(steer);
    
}