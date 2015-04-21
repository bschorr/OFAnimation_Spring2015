#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofBackground(0);
    
    // Add an initial set of boids into the system
    for (int i = 0; i < 200; i++) {
        Boid b(0, 0, 0);
        flock.addBoid(b);
    }
    
    light.setDirectional();
    light.setPosition(1000, 1000, -1000);
    light.lookAt(ofVec3f(0, 0, 0));
    light.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
}

//--------------------------------------------------------------
void ofApp::update(){
    
    flock.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableDepthTest();
    ofSetColor(255, 150);
    
    ofEnableLighting();
    
    light.enable();
    cam.begin();
    flock.draw();
    cam.end();
    ofDisableLighting();

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
