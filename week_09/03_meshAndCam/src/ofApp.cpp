#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    width = 50;
    height = 50;
    res = 10;
    
    mfadt.loadImage("mfadt.png");

    bUsePanCam = false;
    
    //add vertices
    for (int y = -height/2; y < height/2; y++){
        for (int x = -width/2; x < width/2; x++){
            mesh.addVertex(ofPoint(x*res,y*res,0));
        }
    }
    
    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            mesh.addTexCoord(ofVec2f(x, height-y)*res);
        }
    }
    
    
    //add indices
    for (int y = 0; y<height-1; y++){
        for (int x=0; x<width-1; x++){
            mesh.addIndex(x+y*width);				// 0
            mesh.addIndex((x+1)+y*width);			// 1
            mesh.addIndex(x+(y+1)*width);			// 10
            
            mesh.addIndex((x+1)+y*width);			// 1
            mesh.addIndex((x+1)+(y+1)*width);		// 11
            mesh.addIndex(x+(y+1)*width);			// 10
            
        }
    }
    
    panCam.setPosition(500, 0, 0);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    float time = ofGetElapsedTimef()*5;
    
    for (int y = 0; y < height; y++){
        for (int x = 0; x< width; x++){
            
            int index = (y * width) + x;
            
            ofVec3f pos = mesh.getVertex(index);
            pos.z = ofNoise((x+time)*0.05, (y+time)*0.05) * 75.0;
            mesh.setVertex(index, pos);
        }
    }
    
    //pan cam
    float radius = 300.0;
    ofVec3f center = ofVec3f (0, 0, 0);
    float x = cos(ofGetElapsedTimef()*0.5) * radius;
    float y = sin(ofGetElapsedTimef()*0.5) * radius;
    
    panCam.setPosition(x, y, 200);
    panCam.lookAt(center, ofVec3f (0, 0, 1));

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if (bUsePanCam) {
        panCam.begin();
    } else {
        easyCam.begin();
    }

    mfadt.bind();
        mesh.drawWireframe();
    mfadt.unbind();
    
    if (bUsePanCam) {
        panCam.end();
    } else {
        easyCam.end();
    }
    
    string str = "Press space to toggle easycam and pan cam. \nWhen in easy cam, drag around to move object.";
    
    ofDrawBitmapString(str, 20, 20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
        case ' ':
            bUsePanCam = !bUsePanCam;
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
