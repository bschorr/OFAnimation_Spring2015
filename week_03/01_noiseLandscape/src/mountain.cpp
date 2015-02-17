//
//  mountain.cpp
//  01_noiseLandscape
//
//  Created by Bernardo Santos Schorr on 2/16/15.
//
//

#include "mountain.h"

void Mountain::drawMountain(float _x, float _y, float _w, float _h, float _alpha) {
    
    float x1 = _x - _w/2;
    float y1 = _y;
    
    float x2 = _x + _w/2;
    float y2 = _y;
    
    float x3 = _x;
    float y3 = _y - _h;
    
    ofSetColor(0, 255, 0, _alpha);
    
    ofTriangle(x1, y1, x2, y2, x3, y3);
    
}