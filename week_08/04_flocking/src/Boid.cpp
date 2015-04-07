//
//  Boid.cpp
//  04_flocking
//
//  Created by Bernardo Santos Schorr on 4/6/15.
//
//

#include "Boid.h"

Boid::Boid(float x, float y) {
    acc.set(0,0);
    vel.set(ofRandom(-1,1),ofRandom(-1,1));
    pos.set(x,y);
    r = 3.0;
    maxspeed = 3.0;
    maxforce = 0.05;
}

void Boid::update() {
    vel += acc;
    vel.limit(maxspeed);
    pos += vel;
    
    if (pos.x < -r) pos.x = ofGetWidth()+r;
    if (pos.y < -r) pos.y = ofGetHeight()+r;
    if (pos.x > ofGetWidth()+r) pos.x = -r;
    if (pos.y > ofGetHeight()+r) pos.y = -r;
    
}

void Boid::resetForces() {
    acc *= 0;
}

void Boid::applyForce(ofVec2f force) {
    acc += force;
}

void Boid::flock(vector<Boid> boids) {
    
    ofVec2f sep = separate(boids);   // Separation
    ofVec2f ali = align(boids);      // Alignment
    ofVec2f coh = cohesion(boids);   // Cohesion
    
    // Arbitrarily weight these forces
    sep *= 1.5;
    ali *= 1.0;
    coh *= 1.0;
    
    // Add the force vectors to acceleration
    applyForce(sep);
    applyForce(ali);
    applyForce(coh);
}

ofVec2f Boid::seek(ofVec2f target) {
    
    ofVec2f desired = target - pos;
    desired.normalize();
    desired *= maxspeed;
    
    ofVec2f steer = desired - vel;
    steer.limit(maxforce);
    return steer;
}

void Boid::draw() {
    
    ofPushMatrix();
    ofTranslate(pos);
    float rot = atan2( vel.y, vel.x );
    ofRotate(ofRadToDeg(rot));
    
    ofTriangle(-40, 10, -40, -10, 0, 0);
    ofPopMatrix();
}

ofVec2f Boid::separate (vector<Boid> boids) {
    
    float desiredseparation = 25.0f;
    ofVec2f steer = ofVec2f (0, 0);
    int count = 0;
    
    // For every boid in the system, check if it's too close
    for (vector<Boid>::iterator other=boids.begin(); other!=boids.end(); other++) {
        float d = ofDist(pos.x, pos.y, other->pos.x, other->pos.y);
        
        if ((d > 0) && (d < desiredseparation)) {

            ofVec2f diff = pos - other->pos;
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


ofVec2f Boid::align (vector<Boid> boids) {
    
    float neighbordist = 50;
    ofVec2f sum = ofVec2f (0, 0);
    int count = 0;
    
    for (vector<Boid>::iterator other=boids.begin(); other!=boids.end(); other++) {
        float d = ofDist(pos.x, pos.y, other->pos.x, other->pos.y);
        
        if ((d > 0) && (d < neighbordist)) {
            sum += other->vel;
            count++;
        }
    }
    
    if (count > 0) {
        sum /= (float)count;
        sum.normalize();
        sum *= maxspeed;
        ofVec2f steer = sum - vel;
        steer.limit(maxforce);
        return steer;
        
    } else {
        return ofVec2f (0, 0);
    }
}

ofVec2f Boid::cohesion (vector<Boid> boids) {
    float neighbordist = 50;
    ofVec2f sum = ofVec2f(0, 0);
    int count = 0;
    
    for (vector<Boid>::iterator other=boids.begin(); other!=boids.end(); other++) {
        float d = ofDist(pos.x, pos.y, other->pos.x, other->pos.y);
        if ((d > 0) && (d < neighbordist)) {
            sum += other->pos; // Add location
            count++;
        }
    }
    if (count > 0) {
        sum /= count;
        return seek(sum);  // Steer towards the location
    } else {
        return ofVec2f(0,0);
    }
}