#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //assigning value to n int and couting its value and reference
    n = 2;
    cout << n << endl;
    cout << &n << endl;
    
    //line break
    cout << endl;
    
    //making another int p and copying the n value into it
    int p = n;
    p += 3;
    cout << n << endl;
    cout << p << endl;

    //line break
    cout << endl;
 
    //couting memory references for p and n
    cout << &n << endl;
    cout << &p << endl;
    
    //line break
    cout << endl;
    
    //assigning value to m int pointer and couting its address and dereferenced value;
    *m = 5;
    cout << m << endl;
    cout << *m << endl;

    //line break
    cout << endl;
    
    //making another int pointer q and copying the m value into it
    int *q = m;
    *q += 2;
    cout << *q << endl;
    cout << *m << endl;
    
    //line break
    cout << endl;
    
    cout << q << endl;
    cout << m << endl;


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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
