#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    circleOne.setup(ofVec2f(30, 150), ofVec2f(ofGetWindowWidth()-100, 150));
    pct = 0;
    
    circleTwo.setup(ofVec2f(30, 400), ofVec2f(ofGetWindowWidth()-100, 400));
    pct = 0;
    
    circleThree.setup(ofVec2f(30, 650), ofVec2f(ofGetWindowWidth()-100, 650));
    pct = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    pct += 0.01;
    //pct = ofMap (ofGetMouseY(), 0, ofGetHeight(), 0, 1);
    
    circleOne.linear(pct);
    circleTwo.easeOut(pct);
    circleThree.easeIn(pct);
    
    if (pct > 1) {
        pct = 0.0;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    circleOne.draw();
    circleTwo.draw();
    circleThree.draw();
    
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
