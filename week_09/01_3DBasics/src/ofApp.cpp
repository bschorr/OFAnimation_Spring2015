#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    bDrawAxis = false;
    bDrawGrid = false;
    bFill = false;
    bMaterial = false;
    bDrawLight = false;
    
    //lights
    ofSetSmoothLighting(true);
    light.setPointLight();
    light.setDiffuseColor( ofFloatColor(1.f, 0.f, 0.f) );
    //light.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
    
    //material
    material.setShininess( 120 );
    material.setSpecularColor(ofColor(255, 255, 255, 255));
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    light.setPosition(300, 300, 200);

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofEnableDepthTest();
    
    if (bDrawLight) {
        
        light.draw();
        ofEnableLighting();
        light.enable();
            
    }
    
    ofPushMatrix();
    
    ofTranslate(ofGetWindowSize()/2);
    ofRotateX(ofGetElapsedTimeMillis()*0.05);
    ofRotateY(ofGetElapsedTimeMillis()*0.05);
    ofRotateZ(ofGetElapsedTimeMillis()*0.05);
    
    ofNoFill();
    if(bFill) ofFill();
    
    if (bMaterial) material.begin();
    ofDrawBox(0, 0, 0, 100);
    //ofDrawSphere(0, 0, 0, 100);
    //ofDrawPlane(0, 0, 0, 100, 100);
    if (bMaterial) material.end();
    
    if (bDrawAxis) ofDrawAxis(150);
    if (bDrawGrid) ofDrawGrid(300, 10, false, true, true, true);
    
    stringstream buf;
    
    ofPopMatrix();
    
    if (bDrawLight) ofDisableLighting();
    ofDisableDepthTest();
    
    buf << "Press 'a' to toggle axis" << endl <<
    "Press 'g' to toggle grid" << endl <<
    "Press 'f' to toggle fill" << endl <<
    "Press 'l' to toggle lighting" << endl <<
    "Press 'm' to toggle material (only works with lights on and better with fill)" << endl ;
    
    ofDrawBitmapString(buf.str(), 20, 20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
            
        case 'a':
            bDrawAxis = !bDrawAxis;
            break;
            
        case 'g':
            bDrawGrid = !bDrawGrid;
            break;
            
        case 'f':
            bFill = !bFill;
            break;
            
        case 'm':
            bMaterial = !bMaterial;
            break;
            
        case 'l':
            bDrawLight = !bDrawLight;
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
