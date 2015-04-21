#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    //add the vertices and colors
    mesh.addVertex(ofVec3f(-100, -100, 0));
    mesh.addColor(ofFloatColor(1.0,0,0));
    
    mesh.addVertex(ofVec3f( 100, -100, 0));
    mesh.addColor(ofFloatColor(0,1.0,0));
    
    mesh.addVertex(ofVec3f(-100,  100, 0));
    mesh.addColor(ofFloatColor(0,0,1.0));
    
    mesh.addVertex(ofVec3f( 100,  100, 0));
    mesh.addColor(ofFloatColor(1.0,1.0, 0));
    
    //connect the vertices
    mesh.addIndex(0);
    mesh.addIndex(1);
    mesh.addIndex(2);
    
    mesh.addIndex(1);
    mesh.addIndex(2);
    mesh.addIndex(3);

}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    mesh.draw();
    cam.end();
    
    string str = "Drag your mouse to rotate the mesh";
    ofDrawBitmapString(str, 20, 20);
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
