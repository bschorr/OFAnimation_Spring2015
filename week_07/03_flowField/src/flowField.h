//
//  flowField.h
//  03_flowField
//
//  Created by Bernardo Santos Schorr on 3/31/15.
//
//

#pragma once

#include "ofMain.h"

class flowField {
public:
    
    flowField();
    
    void setup(float w, float h, float res);
    
    //functions to set patterns on the flow field
    void setRandom(float scale);
    void setNoise();
    
    //to be called from the particle, so it knows the force of the flow where it stands on
    ofVec2f getForceAt(float x, float y);
    
    //drawing the field
    void draw();
    
    //container for all the flows
    vector<ofVec2f> field;
    
    //The size of the field in pixels, e.g. 1024x768
    int screenWidth;
    int screenHeight;
    
    //The size of the field in number of flows, e.g. 52 x 40
    int fieldWidth;
    int fieldHeight;
    
    //What is the area covered by each flow, e.g. 20x20 pixels
    float resolution;
    
    //Total number of flows in a field
    int totalFlows;
    
};
