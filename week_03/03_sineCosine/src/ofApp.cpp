#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //Turn off auto background to see the sine wave form.
    //ofSetBackgroundAuto(false);
    
    ofNoFill();
    
    ofBackground(0);
    angle = 0.0;
    radius = 100;
    center = ofGetWindowSize()/4;
    
    sinX = center.x + 150;
    cosY = center.y + 150;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    angle += 0.05;
    sinX += 1;
    cosY += 1;
    
    float x = cos(angle)*radius;
    float y = sin(angle)*radius;

    rotCircle.set(center.x + x, center.y + y);
    sinCircle.set(sinX, rotCircle.y);
    cosCircle.set(rotCircle.x, cosY);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    
    //rotating circle
    ofCircle(rotCircle, 10);
    
    //sine wave to Y
    ofCircle(sinCircle, 10);

    //cos wave to X
    ofCircle(cosCircle, 10);
    
    ofSetColor(255, 0, 0);
    ofCircle(center, 5);
    
    ofLine(rotCircle, sinCircle);
    ofLine(rotCircle, cosCircle);
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
