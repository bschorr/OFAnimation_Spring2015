//
//  Boid.cpp
//  04_flocking
//
//  Created by Bernardo Santos Schorr on 4/6/15.
//
//

#include "Boid.h"

Boid::Boid(float x, float y, float z) {
    acc.set(0, 0, 0);
    vel.set(ofRandom(-1,1),ofRandom(-1,1), ofRandom(-1,1));
    pos.set(x, y, z);
    r = 3.0;
    maxspeed = 3.0;
    maxforce = 0.05;
}

void Boid::update() {
    vel += acc;
    vel.limit(maxspeed);
    pos += vel;
    
//    if (pos.x < -(r+ofGetWidth()/2)) pos.x = ofGetWidth()+r;
//    if (pos.y < -(r+ofGetHeight()/2)) pos.y = ofGetHeight()+r;
//    if (pos.x > ofGetWidth()/2+r) pos.x = -r;
//    if (pos.y > ofGetHeight()/2+r) pos.y = -r;
    
}

void Boid::resetForces() {
    acc *= 0;
}

void Boid::applyForce(ofVec3f force) {
    acc += force;
}

void Boid::flock(vector<Boid> boids, ofVec3f attractor) {
    
    ofVec3f sep = separate(boids);   // Separation
    ofVec3f ali = align(boids);      // Alignment
    ofVec3f coh = cohesion(boids);   // Cohesion
    ofVec3f attraction = seek(attractor);
    
    // Arbitrarily weight these forces
    sep *= 1.5;
    ali *= 1.0;
    coh *= 1.0;
    attraction *= 0.8;
    
    // Add the force vectors to acceleration
    applyForce(attraction);
    applyForce(sep);
    applyForce(ali);
    applyForce(coh);
}

ofVec3f Boid::seek(ofVec3f target) {
    
    ofVec3f desired = target - pos;
    desired.normalize();
    desired *= maxspeed;
    
    ofVec3f steer = desired - vel;
    steer.limit(maxforce);
    return steer;
}

void Boid::draw() {
    
    ofPushMatrix();
    ofTranslate(pos);
    
    ofVec3f p1, p2;
    
    p1 = pos;
    p2 = pos + (vel*10);
    
    ofDrawBox(pos, 5);
    ofLine(p1, p2);
    
    ofPopMatrix();
}

ofVec3f Boid::separate (vector<Boid> boids) {
    
    float desiredseparation = 25.0f;
    ofVec3f steer = ofVec3f (0, 0, 0);
    int count = 0;
    
    // For every boid in the system, check if it's too close
    for (vector<Boid>::iterator other=boids.begin(); other!=boids.end(); other++) {
        float d = (other->pos - pos).length();
        
        if ((d > 0) && (d < desiredseparation)) {

            ofVec3f diff = pos - other->pos;
            diff.normalize();
            diff /= d; //stronger if closer
            steer += diff;
            count++; // Keep track of how many
        }
    }
    
    // Average all steering forces
    if (count > 0) {
        steer /= (float) count;
    }

    // calculate final separate steering force
    if (steer.length() > 0) {
        steer.normalize();
        steer *= maxspeed;
        steer -= vel;
        steer.limit(maxforce);
    }
    
    return steer;
}


ofVec3f Boid::align (vector<Boid> boids) {
    
    float neighbordist = 50;
    ofVec3f sum = ofVec3f (0, 0, 0);
    int count = 0;
    
    for (vector<Boid>::iterator other=boids.begin(); other!=boids.end(); other++) {
        float d = (other->pos - pos).length();
        
        if ((d > 0) && (d < neighbordist)) {
            sum += other->vel;
            count++;
        }
    }
    
    if (count > 0) {
        sum /= (float)count;
        sum.normalize();
        sum *= maxspeed;
        ofVec3f steer = sum - vel;
        steer.limit(maxforce);
        return steer;
        
    } else {
        return ofVec3f (0, 0, 0);
    }
}

ofVec3f Boid::cohesion (vector<Boid> boids) {
    float neighbordist = 50;
    ofVec3f sum = ofVec3f(0, 0, 0);
    int count = 0;
    
    for (vector<Boid>::iterator other=boids.begin(); other!=boids.end(); other++) {
        float d = (other->pos - pos).length();
        if ((d > 0) && (d < neighbordist)) {
            sum += other->pos; // Add location
            count++;
        }
    }
    if (count > 0) {
        sum /= count;
        return seek(sum);  // Steer towards the location
    } else {
        return ofVec3f(0, 0, 0);
    }
}