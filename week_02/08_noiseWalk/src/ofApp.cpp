#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    yOffset = 10000.0;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    pos.x = ofMap(ofNoise(ofGetElapsedTimef()), 0, 1, 0, ofGetWidth());
    pos.y = ofMap(ofNoise(ofGetElapsedTimef() + yOffset), 0, 1, 0, ofGetHeight());

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofCircle(pos, 10);

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
