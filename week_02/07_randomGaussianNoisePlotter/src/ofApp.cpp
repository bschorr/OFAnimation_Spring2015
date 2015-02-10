#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    x = 0;
    
    ofSetBackgroundAuto(false);

}

//--------------------------------------------------------------
void ofApp::update(){

    prevX = x;
    x++;
    
    //random
    prevRandomY = randomY;
    randomY = ofRandom(0, 200);
    
    //gaussian
    prevGaussianY = gaussianY;
    float num = ofxGaussian();
    float sd = 33.3;
    float mean = 100;
    gaussianY = (sd * num) + mean;
    
    //noise
    prevNoiseY = noiseY;
    noiseY = ofNoise(ofGetElapsedTimef());
    noiseY = ofMap(noiseY, 0, 1, 0, 200);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    
    //random plotter
    ofPushMatrix();
        ofTranslate(0, 23);
        ofLine(prevX, prevRandomY, x, randomY);
    ofPopMatrix();
    
    //gaussian plotter
    ofPushMatrix();
        ofTranslate(0, 279);
        ofLine(prevX, prevGaussianY, x, gaussianY);
    ofPopMatrix();
    
    //noise plotter
    ofPushMatrix();
        ofTranslate(0, 535);
        ofLine(prevX, prevNoiseY, x, noiseY);
    ofPopMatrix();
    
    ofSetColor(255, 0, 0);
    ofDrawBitmapString("Random", 20, 33);
    ofDrawBitmapString("Gaussian", 20, 289);
    ofDrawBitmapString("Noise", 20, 545);
    
    ofLine(0, 23, ofGetWidth(), 23);
    ofLine(0, 223, ofGetWidth(), 223);
    
    ofLine(0, 279, ofGetWidth(), 279);
    ofLine(0, 479, ofGetWidth(), 479);
    
    ofLine(0, 535, ofGetWidth(), 535);
    ofLine(0, 735, ofGetWidth(), 735);

}

//code for ofxGaussian taken from: https://github.com/andyr0id/ofxGaussian

bool haveNextNextGaussian = false;
float nextNextGaussian;

float ofApp::ofxGaussian() {
    if (haveNextNextGaussian){
        haveNextNextGaussian = false;
        return nextNextGaussian;
    }
    else {
        float v1, v2, s;
        do {
            v1 = 2 * ofRandomf() - 1;
            v2 = 2 * ofRandomf() - 1;
            s = v1 * v1 + v2 * v2;
        }
        while (s >= 1 || s == 0);
        
        float multiplier = sqrt(-2 * log(s)/s);
        nextNextGaussian = v2 * multiplier;
        haveNextNextGaussian = true;
        
        return v1 * multiplier;
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
