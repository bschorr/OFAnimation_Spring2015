#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    drawLines(300,ofGetHeight()/2, ofGetWidth()-300, ofGetHeight()/2);

}

//--------------------------------------------------------------
void ofApp::drawLines(float x1, float y1, float x2, float y2) {
    
    ofLine(x1,y1,x2,y2);
    
    float dx = x2-x1;
    float dy = y2-y1;
    
    if (dx == 0 && dy > 4) {
        drawLines(x1-dy/3,y1,x1+dy/3,y1);
        drawLines(x1-dy/3,y2,x1+dy/3,y2);
    } else if (dy == 0 && dx > 4) {
        drawLines(x1,y1-dx/3,x1,y1+dx/3);
        drawLines(x2,y1-dx/3,x2,y1+dx/3);
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
