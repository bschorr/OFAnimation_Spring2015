#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    gravity.set(0, 0.2);
    color.set(0, 100, 255);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].resetForces();
        particleList[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(color);
    
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].draw(color);
    }
    
    ofSetColor(255, 0, 0);
    string debug = "Drag your mouse around.";
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
    
    Particle p(ofVec2f(x, y));
    particleList.push_back(p);

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
