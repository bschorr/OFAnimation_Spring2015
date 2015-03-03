#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    for (int y = 0; y < ofGetWidth(); y+=20) {
        for (int x = 0; x < ofGetWidth(); x+=20) {
            Mover mover;
            mover.setup(x, y, 0.5);
            moverList.push_back(mover);
        }
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofVec2f mousePos = ofVec2f(ofGetMouseX(), ofGetMouseY());
    
    for (int i = 0; i < moverList.size(); i++) {
        
        ofVec2f repulsion;
        
        ofVec2f diff = mousePos - moverList[i].pos;
        
        float dist = diff.length();
        
        if (dist < 100) {
            repulsion.set(diff.getNormalized()* -0.1);
        } else {
            repulsion.set(0);
        }
        
        moverList[i].resetForces();
        moverList[i].applyForce(repulsion);
        moverList[i].applyDampingForce(0.02);
        moverList[i].checkEdges();
        moverList[i].update();
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < moverList.size(); i++) {
        moverList[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
