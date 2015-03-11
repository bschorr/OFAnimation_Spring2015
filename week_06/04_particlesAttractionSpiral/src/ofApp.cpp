#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    start.set(255, 100, 0);
    end.set(0, 255, 255);
    
    ofNoFill();
    
    ofVec2f init;
    init = ofGetWindowSize()/2;
    
    for (float i = 0; i < 500; i+= 0.1) {
        float x = init.x + (cos(i) * i*2);
        float y = init.y + (sin(i) * i*2);
        
        Mover mover;
        mover.setup(x, y, 0.5);
        moverList.push_back(mover);
    }
    
    bElasticOn = false;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofVec2f mousePos = ofVec2f(ofGetMouseX(), ofGetMouseY());
    
    for (int i = 0; i < moverList.size(); i++) {
        
        ofVec2f repulsion;
        
        ofVec2f diff = mousePos - moverList[i].pos;
        
        float dist = diff.length();
        
        if (dist < 100) {
            repulsion.set(diff.getNormalized()* -0.5);
        } else {
            repulsion.set(0);
        }
        
        moverList[i].resetForces();
        moverList[i].applyForce(repulsion);
        if(bElasticOn) moverList[i].applyElastic();
        moverList[i].applyDampingForce(0.05);
        //moverList[i].checkEdges();
        moverList[i].update();
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackgroundGradient(start, end, OF_GRADIENT_LINEAR);

    ofSetColor(255);
    ofBeginShape();
    
    for (int i = 0; i < moverList.size(); i++) {
        ofVertex(moverList[i].pos.x, moverList[i].pos.y);
    }
    
    ofEndShape();
    
    ofSetColor(0, 0, 255);
    stringstream debug;
    debug << "Move your mouse around." << endl
    << "Hit the spacebar to toggle elastic force";
    ofDrawBitmapString(debug.str(), 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    bElasticOn = !bElasticOn;

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
