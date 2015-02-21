#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    moverOne.setup(50, 500, 1.0);
    gravity.set(0, 0.5);
    wind.set(0.1, 0);
    
    moverTwo.setup(50, 500, 3.0);
    gravity.set(0, 0.5);
    wind.set(0.1, 0);


}

//--------------------------------------------------------------
void ofApp::update(){
    moverOne.resetForces();
    moverOne.applyForce(gravity*moverOne.mass);
    moverOne.applyForce(wind);
    moverOne.applyDampingForce(0.05);
    moverOne.update();
    
    moverTwo.resetForces();
    moverTwo.applyForce(gravity*moverTwo.mass);
    moverTwo.applyForce(wind);
    moverTwo.applyDampingForce(0.05);
    moverTwo.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    moverOne.draw();
    moverTwo.draw();
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
