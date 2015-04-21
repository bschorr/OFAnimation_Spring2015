//
//  Boid.h
//  04_flocking
//
//  Created by Bernardo Santos Schorr on 4/6/15.
//
//

#pragma once
#include "ofMain.h"

class Boid {
public:
    
    Boid(float x, float y, float z);
    void update();
    void draw();
    
    void resetForces();
    void applyForce(ofVec3f force);
    void flock(vector<Boid> boids, ofVec3f attractor);
    
    ofVec3f seek(ofVec3f target);
    ofVec3f separate(vector<Boid> boids);
    ofVec3f align (vector<Boid> boids);
    ofVec3f cohesion(vector<Boid> boids);
    
    ofVec3f pos, vel, acc;
    float r;
    float maxforce, maxspeed;
    
};