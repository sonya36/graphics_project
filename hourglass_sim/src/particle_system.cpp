#include "../include/particle_system.h"

// ParticleSystem::ParticleSystem(int numParticles) : numParticles(numParticles) {
//     // Constructor implementation
//     // particles = new Particle[numParticles]; // Allocate memory for particles
//     // Initialize particles (if necessary)
// }

// ParticleSystem::~ParticleSystem() {
//     // Destructor implementation
//     delete[] particles; // Deallocate memory for particles
// }

// void ParticleSystem::update(float deltaTime) {
//     // Update the particle system (e.g., update positions of particles)
//     for (int i = 0; i < numParticles; ++i) {
//         particles[i].updatePosition(deltaTime);
//     }
// }

// void ParticleSystem::render() const {
//     // Render the particle system (e.g., render each particle)
//     for (int i = 0; i < numParticles; ++i) {
//         // Render particles (placeholder implementation)
//         // This could involve rendering each particle using OpenGL or another rendering framework
//         // Here, we're just printing the particle positions
//         std::cout << "Particle " << i << " position: (" << particles[i].getX() << ", " << particles[i].getY() << ", " << particles[i].getZ() << ")" << std::endl;
//     }
// }





// Particle::Particle(const glm::vec3& position, const glm::vec3& velocity, float lifeTime)
//     : position(position), velocity(velocity), lifeTime(lifeTime) {}

// Particle::~Particle() {}

// void Particle::update(float deltaTime) {
//     // Update position based on velocity
//     position += velocity * deltaTime;
//     // Decrease remaining lifetime
//     lifeTime -= deltaTime;
// }

// glm::vec3 Particle::getPosition() const {
//     return position;
// }

// void Particle::setPosition(const glm::vec3& position) {
//     this->position = position;
// }

// glm::vec3 Particle::getVelocity() const {
//     return velocity;
// }

// void Particle::setVelocity(const glm::vec3& velocity) {
//     this->velocity = velocity;
// }

// float Particle::getLifeTime() const {
//     return lifeTime;
// }

// void Particle::setLifeTime(float lifeTime) {
//     this->lifeTime = lifeTime;
// }

// bool Particle::isAlive() const {
//     return lifeTime > 0.0f;
// }

#include "../include/particle_system.h"

ParticleSystem::ParticleSystem() {}

ParticleSystem::~ParticleSystem() {}

void ParticleSystem::update(float deltaTime) {
    // Update all particles in the system
    for (auto& particle : particles) {
        particle.update(deltaTime);
    }

    // Remove dead particles
    particles.erase(std::remove_if(particles.begin(), particles.end(),
        [](const Particle& particle) { return !particle.isAlive(); }), particles.end());
}

void ParticleSystem::addParticle(const Particle& particle) {
    // Add a new particle to the system
    particles.push_back(particle);
}

void ParticleSystem::clearParticles() {
    // Clear all particles from the system
    particles.clear();
}

const std::vector<Particle>& ParticleSystem::getParticles() const {
    // Get the vector of particles
    return particles;
}



