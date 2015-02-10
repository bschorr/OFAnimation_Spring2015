#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    
    counter = 0.5;
    inc = 0.01;
    
    sineCounter = 0;
    sineInc = 0.01;
    
    pos.set(300, 250);
    sinePos.set(300, 500);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    //linear positioning
    if (counter >= 1 || counter <= 0) inc *= -1;
    
    counter += inc;
    pos.x = ofMap(counter, 0, 1, 300, 660);
    
    //sine positioning
    sineCounter += sineInc;
    sinePos.x = sin(sineCounter*PI);
    sinePos.x = ofMap(sinePos.x, -1, 1, 300, 660);
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofCircle(pos, 10);
    ofCircle(sinePos, 10);
    
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
