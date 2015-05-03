#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofEnableSmoothing();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (k.getCount() > 6) {
        k.restart();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    k.draw();
    
    string debug = "Fractal has " + ofToString(k.getCount()) + " iteration(s).";
    
    ofDrawBitmapString(debug, 20, 20);

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
    k.nextLevel();
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
