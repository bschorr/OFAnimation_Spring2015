//
//  Vehicle.cpp
//  02_pathFollowing
//
//  Created by Bernardo Santos Schorr on 4/5/15.
//
//

#include "Vehicle.h"

void Vehicle::setup(ofVec2f p, float ms, float mf, bool * _debug) {
    pos = p;
    r = 4.0;
    maxSpeed = ms;
    maxForce = mf;
    acc.set(0, 0);
    vel.set(maxSpeed, 0);
    
    debug = _debug;
}

void Vehicle::update() {
    vel += acc;
    vel.limit(maxSpeed);
    pos += vel;
    
    if (pos.x < -r) pos.x = ofGetWidth()+r;
    if (pos.x > ofGetWidth()+r) pos.x = -r;
    
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
    
    ofSetColor(255, 0, 0);
    ofTriangle(-40, 10, -40, -10, 0, 0);
    ofPopMatrix();
    
}

void Vehicle::seek(ofVec2f target) {
    ofVec2f desired = target - pos;
    
    float d = desired.length();
    desired.normalize();
    
    if (d == 0) return;
    
    // Normalize desired and scale to maximum speed
    desired.normalize();
    desired *= maxSpeed;
    
    ofVec2f steer = desired - vel;
    steer.limit(maxForce);
    applyForce(steer);
    
}

void Vehicle::follow(Path p) {
    
    // Predict location 25 (arbitrary choice) frames ahead
    ofVec2f predict = vel;
    predict.normalize();
    predict *= 25;
    ofVec2f predictLoc = pos + predict;
    
    // Look at the line segment
    ofVec2f a = p.start;
    ofVec2f b = p.end;
    
    // Get the normal point to that line
    ofVec2f normalPoint = getNormalPoint(predictLoc, a, b);
    
    // Find target point a little further ahead of normal
    ofVec2f dir = b - a;
    dir.normalize();
    dir *= 10;  // This could be based on velocity instead of just an arbitrary 10 pixels
    ofVec2f target = normalPoint + dir;
    
    // How far away are we from the path?
    float distance = ofDist(predictLoc.x, predictLoc.y, normalPoint.x, normalPoint.y);
    
    // Only if the distance is greater than the path's radius do we bother to steer
    if (distance > p.radius) {
        seek(target);
    }
    
    if (*debug) {
        
        ofSetColor(0);
        ofLine(pos.x, pos.y, predictLoc.x, predictLoc.y);
        ofCircle(predictLoc.x, predictLoc.y, 4);
        
        ofLine(predictLoc.x, predictLoc.y, normalPoint.x, normalPoint.y);
        ofCircle(normalPoint.x, normalPoint.y, 4);
        if (distance > p.radius) ofSetColor(255, 0, 0);
        ofCircle(target.x+dir.x, target.y+dir.y, 8);
        
    }
    
}

ofVec2f Vehicle::getNormalPoint(ofVec2f p, ofVec2f a, ofVec2f b) {
    ofVec2f ap = p - a;
    // Vector from a to b
    ofVec2f ab = b - a;
    ab.normalize(); // Normalize the line
    // Project vector "diff" onto line by using the dot product
    ab *= (ap.dot(ab));
    ofVec2f normalPoint = a + ab;
    return normalPoint;
}

