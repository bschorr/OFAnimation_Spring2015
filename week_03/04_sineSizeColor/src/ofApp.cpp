#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    float sinOfTime = sin(ofGetElapsedTimef());
    size = ofMap(sinOfTime, -1, 1, 100, 300);
    alpha = ofMap(sinOfTime, -1, 1, 0, 255);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255, alpha);
    ofCircle(ofGetWindowSize()/2, size);

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
