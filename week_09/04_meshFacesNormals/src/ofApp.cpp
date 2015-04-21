#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    icoSphere.setRadius(200);
    origTriangles = icoSphere.getMesh().getUniqueFaces();
    
    ofSetSmoothLighting(true);
    
    extLight.setPointLight();
    extLight.setDiffuseColor(ofFloatColor(0.0, 1.0, 0.0));
    extLight.setPosition(ofGetWidth()/2, ofGetHeight()/2, 500);
    
    intLight.setPointLight();
    intLight.setDiffuseColor(ofFloatColor(1.0, 0.0, 0.0));
    intLight.setPosition(ofGetWidth()/2, ofGetHeight()/2, 200);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    //sine for offsetting faces
    sinOfTime = sin(ofGetElapsedTimef());
    offset = ofMap(sinOfTime, -1, 1, 0, 500);
    
    //undulating faces
    triangles = icoSphere.getMesh().getUniqueFaces();
    
    ofVec3f faceNormal;
    for(int i = 0; i < triangles.size(); i++ ) {
        
        faceNormal = triangles[i].getFaceNormal();
        for(int j = 0; j < 3; j++ ) {
            triangles[i].setVertex(j, origTriangles[i].getVertex(j) - faceNormal*offset);
        }
    }
    icoSphere.getMesh().setFromTriangles( triangles );


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableDepthTest();
    ofEnableLighting();
    
    extLight.enable();
    
    cam.begin();
        icoSphere.draw();
        extLight.disable();
    cam.end();
    
    intLight.enable();
    
    cam.begin();
        ofDrawBox(0, 0, 0, 120);
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
