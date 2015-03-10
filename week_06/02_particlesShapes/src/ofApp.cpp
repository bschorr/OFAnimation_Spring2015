#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    gravity.set(0, 0.2);
    
    mouseClicked = false;
    
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    
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
    
    int index = systems.size()-1;
    systems[index].mouseDragged(x, y);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    if(!mouseClicked) {
        particleSystem system(ofVec2f(x, y));
        systems.push_back(system);
    }
    
    mouseClicked = true;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    mouseClicked = false;

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
