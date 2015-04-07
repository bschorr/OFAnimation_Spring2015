//
//  Flock.h
//  04_flocking
//
//  Created by Bernardo Santos Schorr on 4/6/15.
//
//

#pragma once
#include "ofMain.h"
#include "Boid.h"

class Flock {
public:
    
    Flock();
    void update();
    void draw();
    void addBoid(Boid b);
    
    vector<Boid> boids;
    
};
