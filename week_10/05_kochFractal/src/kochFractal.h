//
//  kochFractal.h
//  05_kochFractal
//
//  Created by Bernardo Schorr on 4/26/15.
//
//

#pragma once 

#include "ofMain.h"
#include "kochLine.h"

class kochFractal {
public:
    
    kochFractal();
    void nextLevel();
    void restart();
    int getCount();
    void draw();
    vector<kochLine> iterate (vector<kochLine> before);
    
    ofVec2f start, end;
    vector<kochLine> lines;   // A list to keep track of all the lines
    int count;
    
};
