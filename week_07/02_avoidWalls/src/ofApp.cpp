#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    car.setup();
    d = 100;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    car.resetForces();
    car.avoidWalls(d);
    car.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofFill();
    car.draw();
    
    ofSetColor(255, 0, 0);
    ofNoFill();
    ofRect(d, d, ofGetWidth()-d-d, ofGetHeight()-d-d);

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
