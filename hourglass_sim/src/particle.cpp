// #include "../include/particle.h"

// Particle::Particle(double x, double y, double z, double velocityX, double velocityY, double velocityZ)
//     : x(x), y(y), z(z), velocityX(velocityX), velocityY(velocityY), velocityZ(velocityZ) {
//     // Constructor implementation
// }

// void Particle::updatePosition(double deltaTime) {
//     // Update the position of the particle based on its velocity and time
//     x += velocityX * deltaTime;
//     y += velocityY * deltaTime;
//     z += velocityZ * deltaTime;
// }

// // Getter functions for particle properties
// double Particle::getX() const {
//     return x;
// }

// double Particle::getY() const {
//     return y;
// }

// double Particle::getZ() const {
//     return z;
// }
#include "../include/particle.h"

Particle::Particle(const Vector3& position, const Vector3& velocity, float lifeTime)
    : position(position), velocity(velocity), lifeTime(lifeTime) {}

Particle::~Particle() {}


void Particle::update(float deltaTime) {
    // Update particle position based on velocity
    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;
    position.z += velocity.z * deltaTime;

    // Decrease lifetime
    lifeTime -= deltaTime;
}

Vector3 Particle::getPosition() const {
    return position;
}

void Particle::setPosition(const Vector3& newPosition) {
    position = newPosition;
}

Vector3 Particle::getVelocity() const {
    return velocity;
}

void Particle::setVelocity(const Vector3& newVelocity) {
    velocity = newVelocity;
}

float Particle::getLifeTime() const {
    return lifeTime;
}

void Particle::setLifeTime(float newLifeTime) {
    lifeTime = newLifeTime;
}

bool Particle::isAlive() const {
    return lifeTime > 0.0f;
}
