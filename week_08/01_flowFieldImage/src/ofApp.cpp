#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetBackgroundAuto(false);
    
    morrison.setImageType(OF_IMAGE_GRAYSCALE);
    morrison.loadImage("morrison.jpg");
    
    flowField.setup(ofGetWidth(), ofGetHeight(), 20.0);
    //flowField.setRandom(2.0);
    //flowField.setNoise();
    flowField.setImage(morrison);
    
    for (int i = 0; i < 50000; i++) {
        Particle myParticle;
        myParticle.setup();
        particles.push_back(myParticle);
    }
    
    bDrawField = false;
    bDrawBackground = false;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < particles.size(); i++){
        
        particles[i].resetForces();
        
        //get the force of the flowfield at the particle position
        ofVec2f frc = flowField.getForceAt(particles[i].pos.x, particles[i].pos.y);
        
        //apply force to the particle
        particles[i].applyForce(frc);
        particles[i].applyDampingForce(0.01);
        particles[i].update();
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255, 0, 0);
    
    if (bDrawField) flowField.draw();
    
    ofSetColor(0, 3);
    for (int i = 0; i < particles.size(); i++){
        particles[i].draw();
    }
    
    stringstream buf;
    
    buf << "Press 'f' to toggle flowfield draw" << endl <<
    "Press 'b' to toggle background draw" << endl;
    
    ofDrawBitmapString(buf.str(), 20, 20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key) {
        case 'f' | 'F':
            bDrawField = !bDrawField;
            break;
        case 'b' | 'B' :
            bDrawBackground = !bDrawBackground;
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
