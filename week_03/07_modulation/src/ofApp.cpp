#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundAuto(false);
    ofBackground(0);
    
    sinPos.set(0, 200);
    fmPos.set(0, 400);
    amPos.set(0, 600);
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    prevSinPos = sinPos;
    prevAmPos = amPos;
    prevFmPos = fmPos;
    
    float time = ofGetElapsedTimeMillis()*0.001;
    
    float sinOfTime = sin(time);
    float fmSinOfTime = sin(sin(time)*20);
    float amSinOfTime = sin(time) * sin(time*20);
    
    sinPos.y = 200 + (sinOfTime * 80);
    fmPos.y = 400 + (fmSinOfTime * 80);
    amPos.y = 600 + (amSinOfTime * 80);
    
    sinPos.x++;
    fmPos.x++;
    amPos.x++;

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofLine(prevSinPos, sinPos);
    ofLine(prevFmPos, fmPos);
    ofLine(prevAmPos, amPos);
    

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
