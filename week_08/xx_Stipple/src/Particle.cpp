//
//  Particle.cpp
//  GridParticles
//
//  Created by Charlie Whitney on 9/23/13.
//
//

#include "Particle.h"

Particle::Particle( ofVec2f position, ofVec2f velocity ) {
    pos = position;
    vel = velocity;
    radius = 3.0;
    age = 0;
    lifespan = floor( ofRandom(60,100) );
    decay = ofRandom( 0.95, 0.951 );
    decay = 0.01;
    
    mass = radius * radius * 0.0001f + 0.01f;
}

void Particle::update( const ofImage &img, ofVec2f mousePos ){
    
    vel += acc;
    
    float maxVel = 2.0;
    if( vel.lengthSquared() > maxVel*maxVel ){
        vel.normalize();
        vel *= maxVel;
    }
    
    pos += vel;
    vel *= decay;
    acc.set(0,0);
    
    // we don't care about age any more
//    age++;
//    if( age > lifespan ){
//        bIsDead = true;
//    }
    
//    float agePct = 1.0 - ((float)age / (float)lifespan);
//    radius = agePct * 3.0;
    
    radius = img.getColor(pos.x, pos.y).r / 255.0 * 3.0;
    
    mass = radius * radius * 0.0001f + 0.01f;
}

void Particle::draw() {
    ofSetColor( 255 );
    ofCircle(pos, 4 );
}