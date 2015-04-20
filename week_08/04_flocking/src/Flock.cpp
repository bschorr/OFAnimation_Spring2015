//
//  Flock.cpp
//  04_flocking
//
//  Created by Bernardo Santos Schorr on 4/6/15.
//
//

#include "Flock.h"


Flock::Flock() {
}

void Flock::update() {
    
    for( vector<Boid>::iterator b=boids.begin(); b!=boids.end(); b++){
        b->resetForces();
        b->flock(boids);
        b->update();
    }
}

void Flock::draw() {
    
    for (vector<Boid>::iterator b=boids.begin(); b!=boids.end(); b++) {
        b->draw();
    }
}

void Flock::addBoid(Boid b) {
    boids.push_back(b);
}