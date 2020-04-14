#include "Particle.h"
#include <cmath>
#include <iostream>

using namespace std;

Particle::Particle(int m_width, int m_height, float scaler, int m_radius)
    : width(m_width), height(m_height), radius(m_radius) {
    velocity.set(ofRandom(-1.f, 1.f), ofRandom(-1.f, 1.f));
    velocity.scale(scaler);
    pos.y = (float)(m_height / 2);
    pos.x = (float)(m_width / 2);
}

Particle::Particle(int m_width, int m_height, float start_x, float start_y,
                   float scaler, int m_radius)
    : width(m_width), height(m_height), radius(m_radius) {
    velocity.set(ofRandom(-1.f, 1.f), ofRandom(-1.f, 1.f));
    velocity.scale(scaler);
    pos.x = start_x;
    pos.y = start_y;
}

void Particle::updatePosition() {
    pos.x = ofClamp(pos.x, radius, width - radius);
    pos.y = ofClamp(pos.y, radius, height - radius);

    if (pos.x <= radius)
        velocity.x = abs(velocity.x * 0.9); // bounce horizontally
    else if (pos.x >= width - radius)
        velocity.x = -abs(velocity.x * 0.9); // bounce horizontally
    if (pos.y <= radius)
        velocity.y = abs(velocity.y * 0.9); // bounce vertically
    else if (pos.y >= height - radius)
        velocity.y = -abs(velocity.y * 0.9); // bounce vertically

    velocity *= 0.9999; // friction

    // update position
    pos += velocity;

    // velocity.rotateRad(ofRandom(-M_PI / 2, M_PI / 2)); // BROWNIAN MOTION
}

Particle Particle::collision(Particle other_p) {
    ofVec2f normal = pos - other_p.pos;
    normal.normalize();

    float proj_vel = velocity.dot(normal);
    float proj_vel_other = other_p.velocity.dot(normal);
    float vel_difference = proj_vel - proj_vel_other;

    velocity = velocity - vel_difference * normal;
    other_p.velocity = other_p.velocity + vel_difference * normal;

    updatePosition();
    other_p.updatePosition();

    velocity *= 0.7;         // friction (stickiness!)
    other_p.velocity *= 0.7; // friction (stickiness!)

    return other_p;
}
