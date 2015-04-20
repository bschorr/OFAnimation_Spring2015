//
//  Path.h
//  02_pathFollowing
//
//  Created by Bernardo Santos Schorr on 4/5/15.
//
//

#pragma once
#include "ofMain.h"

class Path {
public:
    
    Path();
    void draw();
    
    ofVec2f start, end;
    float radius;
    
};
