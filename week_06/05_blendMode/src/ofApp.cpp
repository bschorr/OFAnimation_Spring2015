#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    gravity.set(0, 0.2);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < systems.size(); i++) {
        systems[i].update(gravity);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < systems.size(); i++) {
        systems[i].draw();
    }
    
    ofSetColor(255, 0, 0);
    stringstream debug;
    debug << "Click to add a comet.";
    ofDrawBitmapString(debug.str(), 20, 20);

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
    
    particleSystem system;
    systems.push_back(system);

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
