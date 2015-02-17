#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    angle = ofGetElapsedTimef();
    
    ofVec2f center = ofGetWindowSize()/2;
    
    float lissajousSin = sin(angle * 10.0);
    float lissajousCos = cos(angle * 9.5);
  
    prevPos = pos;
    
    pos.x = center.x + lissajousCos * 200;
    pos.y = center.y + lissajousSin * 200;
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofLine(prevPos, pos);

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
