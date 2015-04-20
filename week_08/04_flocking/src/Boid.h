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
    
    Boid(float x, float y);
    void update();
    void draw();
    
    void resetForces();
    void applyForce(ofVec2f force);
    void flock(vector<Boid> boids);
    
    ofVec2f seek(ofVec2f target);
    ofVec2f separate(vector<Boid> boids);
    ofVec2f align (vector<Boid> boids);
    ofVec2f cohesion(vector<Boid> boids);
    
    ofVec2f pos, vel, acc;
    float r;
    float maxforce, maxspeed;
    
};