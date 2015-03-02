#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    mover.setup(50, 500, 1.0);


}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofVec2f mousePos = ofVec2f(ofGetMouseX(), ofGetMouseY());
    ofVec2f diff = mousePos - mover.pos;
    
    //set diff to depend on distance
    //attraction.set(diff*0.001);
    
    //or not
    attraction.set(diff.getNormalized()*0.5);
    
    mover.resetForces();
    mover.applyForce(attraction);
    mover.applyDampingForce(0.05);
    mover.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    mover.draw();
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
