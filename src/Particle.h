#ifndef __PARTICLE_H__
#define __PARTICLE_H__

#pragma once
#include "ofMain.h"

class Particle {
public:
  float x, y;
  int width, height;

  Particle(int m_width, int m_height);
  Particle(int m_width, int m_height, float start_x, float start_y);

  void updatePosition();

private:
  float MASS = 0.01;
  ofVec2f velocity;
};

#endif
