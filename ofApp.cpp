/*
 * Simple particle engine
 *
 * TODO: - process collision only once!
 *   - in-elastic bounce (elastic bounce...)
 *   - implement threads! so that update-function is called more often!
 *   - git shared between mac/linux (DONE!)
 *   - readme..
 *
 *
 */
#include "ofApp.h"
#include <cstdlib>
#include <iostream>

//--------------------------------------------------------------
//
void ofApp::setup() {
    ofSetCircleResolution(50);
    ofSetFrameRate(60);
    for (int index = 0; index < N_PARTICLES; index++)
        particles.push_back(
            Particle(ofGetWidth(), ofGetHeight(), ofRandom(ofGetWidth()),
                     ofRandom(ofGetHeight()), INITIAL_VEL, RADIUS));
}
//--------------------------------------------------------------
void ofApp::update() {
    for (int index = 0; index < N_PARTICLES; index++) {
        for (int inner_i = index + 1; inner_i < N_PARTICLES;
             inner_i++) // simple collision detection (inaccurate!)
        {
            float square_dist =
                particles[index].pos.squareDistance(particles[inner_i].pos);
            float radius_check = particles[index].radius * 2;
            if (square_dist <= radius_check * radius_check)
                if (sqrt(square_dist) <=
                    radius_check) // save cpu by only calling sqrt if closeby!
                    particles[inner_i] =
                        particles[index].collision(particles[inner_i]);
        }
        // printf("collision!");

        particles[index].updatePosition();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(10);
    ofSetColor(255);

    for (int index = 0; index < N_PARTICLES; index++)
        ofDrawCircle(particles[index].pos.x, particles[index].pos.y,
                     particles[index].radius);
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
