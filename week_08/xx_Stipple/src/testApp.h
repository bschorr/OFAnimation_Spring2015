#pragma once

#include "ofMain.h"
#include "Particle.h"

class testApp : public ofBaseApp{

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
		
        void addParticle(float x, float y);
        void repulseParticles();
    
        vector<Particle>    particleList;
    
    ofImage 	sampler;
    bool        bMouseIsDown;
    ofVec2f     lastMousePos;
    ofVec2f     mouseVel;
};
