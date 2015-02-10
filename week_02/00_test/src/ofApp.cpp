#include "ofApp.h"

//--------------------------------------------------------------
bool haveNextNextGaussian = false;
float nextNextGaussian;

float ofxGaussian() {
    if (haveNextNextGaussian){
        haveNextNextGaussian = false;
        return nextNextGaussian;
    }
    else {
        float v1, v2, s;
        do {
            v1 = 2 * ofRandomf() - 1;
            v2 = 2 * ofRandomf() - 1;
            s = v1 * v1 + v2 * v2;
        }
        while (s >= 1 || s == 0);
        
        float multiplier = sqrt(-2 * log(s)/s);
        nextNextGaussian = v2 * multiplier;
        haveNextNextGaussian = true;
        
        return v1 * multiplier;
    }
}

void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofBackground(255);
    ofSetColor(0);
}

void ofApp::update(){
    
}

void ofApp::draw(){
    
    float num = ofxGaussian();
    float sd = 33;
    float mean = ofGetWidth() / 2;
    
    float x = (sd * num) + mean;
    
    ofSetColor(255, 10);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(0);
    ofEllipse(x, ofGetHeight() / 2, 16, 16);
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
