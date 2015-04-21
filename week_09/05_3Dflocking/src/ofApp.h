//This example is mostly a port from Daniel Shiffman's book Nature of Code example 6.9 - Flocking.

#pragma once

#include "ofMain.h"
#include "Flock.h"
#include "Boid.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofEasyCam cam;
    Flock flock;
    
    ofLight light;
		
};
