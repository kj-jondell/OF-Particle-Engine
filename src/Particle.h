#ifndef __PARTICLE_H__
#define __PARTICLE_H__

#pragma once
#include "ofMain.h"

class Particle {
public:
  int width, height, radius;
  ofVec2f velocity, pos;

  Particle(int m_width, int m_height, float scaler = 1, int m_radius = 10);
  Particle(int m_width, int m_height, float start_x, float start_y,
           float scaler = 1, int m_radius = 10);

  void updatePosition();
  Particle collision(Particle other_p);

private:
  float MASS = 0.01;
};

#endif
