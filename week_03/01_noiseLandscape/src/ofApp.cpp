#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofEnableAlphaBlending();
    mult = 0.005;
    z = 0.0;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    z+= 0.01;

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int x = 50;  x < ofGetWidth()-50; x+= 30) {
        for (int y = 50;  y < ofGetHeight()-50; y+= 30){
            
            Mountain m;
            float noise = ofNoise(x*mult, y*mult, z);
            float w = ofMap(noise, 0, 1, 20, 50);
            float h = ofMap(noise, 0, 1, 40, 70);
            float alpha = ofMap(noise, 0, 1, 0, 255);
            
            if(noise > 0.1) {
            m.drawMountain(x, y, w, h, alpha);
            }
            
            
        }
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
