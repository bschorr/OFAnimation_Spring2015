#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    mult = 0.01;
    noisePixels.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_COLOR);    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int y = 0; y < ofGetHeight(); y++) {
        for (int x = 0; x < ofGetWidth(); x++) {
            ofFloatColor color = ofFloatColor(ofNoise(x*mult, y*mult));
            noisePixels.setColor(x, y, color);
        }
    }
    
    noiseImg.setFromPixels(noisePixels.getPixels(), noisePixels.getWidth(), noisePixels.getHeight(), OF_IMAGE_COLOR);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    noiseImg.draw(0, 0);
    
    ofSetColor(255, 0, 0);
    
    stringstream debug;
    
    debug << "Press up/down arrows to change noise multiplier" << endl
    << "Multiplier: " << mult << endl;
    
    ofDrawBitmapString(debug.str(), 30, 30);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
        case OF_KEY_UP:
            mult *= 2;
            break;
            
        case OF_KEY_DOWN:
            mult *= 0.5;
            break;
            
        default:
            break;
    }
    

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
