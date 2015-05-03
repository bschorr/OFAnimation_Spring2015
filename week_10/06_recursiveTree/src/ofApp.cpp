// Created by Bernardo Schorr
//
// Based of:
// Recursive Tree
// Daniel Shiffman <http://www.shiffman.net>
// Nature of Code, Chapter 8

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();

}

//--------------------------------------------------------------
void ofApp::update(){
    
    theta = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 180);
    wind = ofNoise(ofGetElapsedTimeMillis()*0.0005) * 10;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofTranslate(ofGetWidth()/2, ofGetHeight());
    branch(200);

}

//--------------------------------------------------------------
void ofApp::branch(float len) {
    
    float sw = ofMap(len,2,120,1,10);
    ofSetLineWidth(sw);
    
    ofRotate(wind);
    ofLine(0, 0, 0, -len);
    
    // Move to the end of that line
    ofTranslate(0, -len);
    
    len *= 0.66;
    
    // exit condition
    if (len > 12) {
        
        //right branches
        ofPushMatrix();
        ofRotate(theta+wind);
        branch(len);
        ofPopMatrix();
        
        //middle branches
        ofPushMatrix();
        ofRotate(wind);
        branch(len);
        ofPopMatrix();
        
        //left branches
        ofPushMatrix();
        ofRotate(-theta+wind);
        branch(len);
        ofPopMatrix();
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
