#include "ofApp.h"
#include <iostream>

//--------------------------------------------------------------
//
void ofApp::setup() {
  ofSetCircleResolution(50);

  particles = new Particle[N_PARTICLES];

  for (int index = 0; index < N_PARTICLES; index++)
    particles[index] = new Particle(ofGetWidth(), ofGetHeight());

  // v1 *= 25; // scaling
  // v2 *= 15; // scaling
}

//--------------------------------------------------------------
void ofApp::update() {
  for (int index = 0; index < N_PARTICLES; index++)
    particles[index].updatePosition();
  //  if (y2 < 0 || y2 > ofGetHeight())
  //    v2.y = -v2.y;
  //  if (x2 < 0 || x2 > ofGetWidth())
  //    v2.x = -v2.x;
  //
  //  x2 = x2 + v2.x; // ofWrap(x + v1.x, 0, ofGetWidth());
  //  y2 = y2 + v2.y; // ofWrap(y + v1.y, 0, ofGetHeight());
  //
  //  if (y < 0 || y > ofGetHeight())
  //    v1.y = -v1.y;
  //  if (x < 0 || x > ofGetWidth())
  //    v1.x = -v1.x;
  //
  //  x = x + v1.x; // ofWrap(x + v1.x, 0, ofGetWidth());
  //  y = y + v1.y; // ofWrap(y + v1.y, 0, ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofBackground(100);
  ofSetColor(255);
  for (int index = 0; index < N_PARTICLES; index++)
    ofDrawEllipse(particles[index].x, particles[index].y, 10, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
