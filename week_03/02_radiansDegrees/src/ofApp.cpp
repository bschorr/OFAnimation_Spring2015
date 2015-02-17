#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    degrees = 0;
    radius = 300;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    degrees++;
    
    if(degrees > 359) degrees = 0;
    
    sine = sin(ofDegToRad(degrees));
    cosine = cos(ofDegToRad(degrees));
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofVec2f center = ofGetWindowSize()/2;
    float y = center.y + (sine * radius);
    float x = center.x + (cosine * radius);
    
    ofSetColor(255);
    ofCircle(center, 5);
    ofCircle(x, y, 15);
    
    stringstream debug;
    
    debug <<
    "Degrees: " << degrees << endl <<
    "PI Radians: " << ofDegToRad(degrees) / PI << endl <<
    "Sine: " << sine << endl <<
    "Cosine: " << cosine << endl;
    
    ofSetColor(255, 0, 0);
    ofDrawBitmapString(debug.str(), x + 25, y);
    
    ofLine(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight());
    ofLine(0, ofGetHeight()/2, ofGetWidth(), ofGetHeight()/2);
    ofLine(x, y, x, center.y);
    ofLine(x, y, center.x, y);
    ofLine(center.x, center.y, x, y);

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
