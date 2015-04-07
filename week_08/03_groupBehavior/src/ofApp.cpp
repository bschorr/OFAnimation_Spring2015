#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    for (int i = 0; i < 200; i++){
        Particle myParticle;
        particleList.push_back(myParticle);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofVec2f mousePos;
    mousePos.set(ofGetMouseX(), ofGetMouseY());
    
    for (int i = 0; i < particleList.size(); i++){
        particleList[i].resetForces();
    }
    
    for (int i = 0; i < particleList.size(); i++){
        

        particleList[i].applyRepulsion(mousePos, 200, 1.4);
        
        for (int j = 0; j < i; j++){
            particleList[i].applyRepulsion(particleList[j], 50, 0.4);
            particleList[i].applyAttraction(particleList[j], 1000, 0.005);
        }
    }
    
    for (int i = 0; i < particleList.size(); i++){
        particleList[i].applyDampingForce(0.1);
        particleList[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    
    for (int i = 0; i < particleList.size(); i++){
        particleList[i].draw();
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
