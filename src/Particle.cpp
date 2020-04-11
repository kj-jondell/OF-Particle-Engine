#include "Particle.h"
#include <iostream>

Particle::Particle(int m_width, int m_height)
    : x((float)(m_width / 2)), y((float)(m_height / 2)), width(m_width),
      height(m_height) {
  velocity.set(ofRandom(-1.f, 1.f), ofRandom(-1.f, 1.f));
}

Particle::Particle(int m_width, int m_height, float start_x, float start_y)
    : x(start_x), y(start_y), width(m_width), height(m_height) {
  velocity.set(ofRandom(-1.f, 1.f), ofRandom(-1.f, 1.f));
}

void Particle::updatePosition() {
  if (x < 0 || x > width)
    velocity.x = -velocity.x; // bounce horizontally
  if (y < 0 || y > height)
    velocity.y = -velocity.y; // bounce vertically

  // update position
  x += velocity.x;
  y += velocity.y;
}
