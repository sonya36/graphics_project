// #ifndef PARTICLE_SYSTEM_H
// #define PARTICLE_SYSTEM_H

// #include "particle.h" // Include the Particle class header

// class ParticleSystem {
// public:
//     // Constructor
//     ParticleSystem(int numParticles);
    
//     // Destructor
//     ~ParticleSystem();

//     // Function to update the particle system
//     void update(float deltaTime);

//     // Function to render the particle system
//     void render() const;

// private:
//     // Private member variables
//     Particle* particles; // Array to store particles
//     int numParticles; // Number of particles in the system
// };

// #endif // PARTICLE_SYSTEM_H

#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include "particle.h"
#include <vector>

class ParticleSystem {
public:
    ParticleSystem(); // Constructor
    ~ParticleSystem(); // Destructor

    void update(float deltaTime); // Update all particles in the system
    void addParticle(const Particle& particle); // Add a new particle to the system
    void clearParticles(); // Clear all particles from the system

    const std::vector<Particle>& getParticles() const; // Get the vector of particles

private:
    std::vector<Particle> particles; // Vector to store particles
};

#endif // PARTICLE_SYSTEM_H


