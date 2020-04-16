#pragma once

#include "Particle.h"
#include "ofMain.h"
#include "ofxOsc.h"

#define N_PARTICLES 20
#define INITIAL_VEL 5.f
#define RADIUS 10
#define OSC_PORT 57121

class ofApp : public ofBaseApp {
  public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

  private:
    ofxOscSender sender;
    vector<Particle> particles;
};
