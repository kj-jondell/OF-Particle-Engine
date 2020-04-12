#include "Particle.h"
#include <iostream>

Particle::Particle(int m_width, int m_height, float scaler, int m_radius)
    : width(m_width), height(m_height), radius(m_radius) {
  velocity.set(ofRandom(-1.f, 1.f) * scaler, ofRandom(-1.f, 1.f) * scaler);
  pos.y = (float)(m_height / 2);
  pos.x = (float)(m_width / 2);
}

Particle::Particle(int m_width, int m_height, float start_x, float start_y,
                   float scaler, int m_radius)
    : width(m_width), height(m_height), radius(m_radius) {
  velocity.set(ofRandom(-1.f, 1.f) * scaler, ofRandom(-1.f, 1.f) * scaler);
  pos.x = start_x;
  pos.y = start_y;
}

void Particle::updatePosition() {
  if (pos.x < radius || pos.x > width - radius)
    velocity.x = -velocity.x; // bounce horizontally
  if (pos.y < radius || pos.y > height - radius)
    velocity.y = -velocity.y; // bounce vertically

  // update position
  pos += velocity;

  pos.x = ofClamp(pos.x, radius, width - radius);
  pos.y = ofClamp(pos.y, radius, height - radius);
}

Particle Particle::collision(Particle other_p) {
  ofVec2f n_velocity =
      velocity - 0.11 *
                     ((velocity - other_p.velocity).dot(pos - other_p.pos) /
                      (pos - other_p.pos).length()) *
                     (pos - other_p.pos);
  other_p.velocity = other_p.velocity -
                     0.11 *
                         ((other_p.velocity - velocity).dot(other_p.pos - pos) /
                          (other_p.pos - pos).length()) *
                         (other_p.pos - pos);
  velocity = n_velocity;
  return other_p;
}
