#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofNoFill();
    ofSetCircleResolution(60);
    
    for (float i = 0; i < 10; i++) {
        customCircle myCirc;
        myCirc.setup(i/5);
        circleList.push_back(myCirc);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < circleList.size(); i++) {
        circleList[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < circleList.size(); i++) {
        circleList[i].draw();
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
