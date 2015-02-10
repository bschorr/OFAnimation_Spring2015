#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    bIsFill = true;
    bRectMode = false;
    circleRes = 60;
    
    ofSetCircleResolution(circleRes);
    //ofSetLineWidth(5);

}

//--------------------------------------------------------------
void ofApp::update(){
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofCircle(100, 200, 50);
    ofRect(300, 200, 150, 50);
    ofEllipse(200, 400, 250, 100);
    ofTriangle(600, 300, 700, 300, 650, 200);
    
    ofBeginShape(); {
        ofVertex(600, 400);
        ofVertex(550, 600);
        ofVertex(700, 700);
        ofVertex(650, 400);
    } ofEndShape(true);
    
    //bezier
    
    ofBeginShape(); {
        ofVertex(100, 600);
        ofBezierVertex(200, 700, 300, 500, 400, 600);
    }ofEndShape();
    
    
    stringstream rules;
    
    rules << "Press 'f' to toggle fill" << endl
    << "Press 'r' to toggle rect mode" << endl << endl
    << "Press up and down arrows to change circle resolution"<< endl
    << "Circle resolution: " << circleRes << endl;
    ofDrawBitmapString(rules.str(), 10, 20);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
            if (bIsFill) {
                ofNoFill();
            } else {
                ofFill();
            }
            bIsFill = ! bIsFill;
            
            break;
        
        case OF_KEY_UP:
            circleRes += 3;
            ofSetCircleResolution(circleRes);
            break;
        
        case OF_KEY_DOWN:
            if(circleRes > 3 )circleRes -= 3;
            ofSetCircleResolution(circleRes);
            break;
            
        case 'r':
            if (bRectMode) {
                ofSetRectMode(OF_RECTMODE_CENTER);
            } else {
                ofSetRectMode(OF_RECTMODE_CORNER);
            }
            
            bRectMode = !bRectMode;
            
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
