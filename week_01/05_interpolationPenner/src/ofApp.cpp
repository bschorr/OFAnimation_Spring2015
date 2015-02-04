#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    myCircle.setup(ofVec2f(0, 500), ofVec2f(500, 500));
    
    pct = 0.0;
    currIter = 0.0;
    totalIter = 100.0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (currIter < totalIter) {
        currIter++;
    }
    
    pct = easeInOutElastic(currIter, 0.0, 1.0, totalIter);
    myCircle.update(pct);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    myCircle.draw();
    
}

//--------------------------------------------------------------
float ofApp::easeInElastic (float t,float b , float c, float d) {
    if (t==0) return b;  if ((t/=d)==1) return b+c;
    float p=d*.3f;
    float a=c;
    float s=p/4;
    float postFix =a*pow(2,10*(t-=1)); // this is a fix, again, with post-increment operators
    return -(postFix * sin((t*d-s)*(2*PI)/p )) + b;
}
float ofApp::easeOutElastic(float t,float b , float c, float d) {
    if (t==0) return b;  if ((t/=d)==1) return b+c;
    float p=d*.3f;
    float a=c;
    float s=p/4;
    return (a*pow(2,-10*t) * sin( (t*d-s)*(2*PI)/p ) + c + b);
}

float ofApp::easeInOutElastic(float t,float b , float c, float d) {
    if (t==0) return b;  if ((t/=d/2)==2) return b+c;
    float p=d*(.3f*1.5f);
    float a=c;
    float s=p/4;
    
    if (t < 1) {
        float postFix =a*pow(2,10*(t-=1)); // postIncrement is evil
        return -.5f*(postFix* sin( (t*d-s)*(2*PI)/p )) + b;
    }
    float postFix =  a*pow(2,-10*(t-=1)); // postIncrement is evil
    return postFix * sin( (t*d-s)*(2*PI)/p )*.5f + c + b;
    
}

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
    
    myCircle.setNewPosition(ofVec2f(x, y));
    currIter = 0.0;
    
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
