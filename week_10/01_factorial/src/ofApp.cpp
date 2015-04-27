#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    keypress = 0;
    result = 0;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    stringstream debug;
    
    debug << "You pressed: " + ofToString(keypress) << endl <<
    "Factorial result for "+ ofToString(keypress) + " is: " + ofToString(result);
    
    ofDrawBitmapString(debug.str(), 20, 20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //In ASCII keys 0-9 are represented 48-57. This is a "poor man's" ASCII converter.
    int num = key - 48;
    
    if (num >= 0 && num <= 9) {
        keypress = num;
        result = factorial(num);
    }

}

//--------------------------------------------------------------
int ofApp::factorial (int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
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
