#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground( 0 );
    bIsTreeMode = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    
    if (bIsTreeMode) {
        ofTranslate( ofGetWidth()/2, ofGetWindowHeight() );
        ofRotate( -90 );
    } else {
        ofTranslate(0, ofGetHeight());
    }
    
        turtle.draw();
    
    ofPopMatrix();
    
    stringstream buf;
    
    buf << "Press keys 1, 2, 3 to toggle drawing modes." << endl <<
    "Click your mouse to add iterations." << endl <<
    "Currently drawing: " + mode << endl;
    
    ofDrawBitmapString(buf.str(), 20, 20);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    vector<Rule> myRules;
    bIsTreeMode = false;
    
    switch (key) {
        case '1':
            myRules.push_back( Rule('F',"FF+[+F-F-F]-[-F+F+F]") );
            system.setup("F", myRules);
            turtle.setup( 15, 25 );
            bIsTreeMode = true;
            mode = "Tree";
            break;
            
        case '2':
            myRules.push_back( Rule('F',"F[F]-F+F[--F]+F-F") );
            system.setup( "F-F-F-F", myRules );
            turtle.setup( 10, 90 );
            mode = "Boxes";
            break;
            
        case '3':
            myRules.push_back( Rule('F',"F--F--F--G") );
            myRules.push_back( Rule('G',"GG") );
            system.setup("F--F--F", myRules);
            turtle.setup( 10, 60 );
            mode = "Sierpinski";
            break;
            
        default:
            break;
    }
    
    turtle.setInstructions( system.sentence );

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
    system.addGeneration();
    turtle.setInstructions( system.sentence );
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
