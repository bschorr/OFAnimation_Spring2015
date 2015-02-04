#pragma once

#include "ofMain.h"
#include "customCircle.h"

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
    
    //This is using Penner elastic equations. Check out other Penner equations!
    float easeInElastic (float t,float b , float c, float d);
    float easeOutElastic (float t,float b , float c, float d);
    float easeInOutElastic (float t,float b , float c, float d);
    
    //t == currentIteration
    //b == startValue
    //c == changeInValue
    //d == totalIterations
	
    customCircle myCircle;
    float pct;
    float currIter, totalIter;
    
    
};
