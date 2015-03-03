#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    gravity.set(0, 0.2);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].update();
    }
    
    while (particleList.size() > 1000) {
        particleList.erase(particleList.begin());
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].draw();
        if(i > 0)ofLine(particleList[i].pos, particleList[i-1].pos);
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
    
    ofVec2f vel;
    vel.x = x - ofGetPreviousMouseX();
    vel.y = y - ofGetPreviousMouseY();
    Particle particle(ofVec2f(x, y), vel*0.3);
    particleList.push_back(particle);

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
