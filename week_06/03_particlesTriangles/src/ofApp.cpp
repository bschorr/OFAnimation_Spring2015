#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    gravity.set(0, 0.2);
    
    mouseClicked = false;
    ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < systems.size(); i++) {
        systems[i].update(gravity);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    for (int i = 0; i < systems.size(); i++) {
        systems[i].draw();
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
