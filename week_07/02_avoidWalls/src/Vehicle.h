//
//  Vehicle.h
//  01_steer
//
//  Created by Bernardo Santos Schorr on 3/31/15.
//
//

#pragma once
#include "ofMain.h"

class Vehicle {
public:
    
    void setup();
    void update();
    void draw();
    
    void resetForces();
    void applyForce(ofVec2f force);
    void avoidWalls(float d);
    
    ofVec2f pos, vel, acc;
    float mass;
    
    float maxSpeed, maxForce;
    
};