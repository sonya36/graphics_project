// #ifndef PARTICLE_H
// #define PARTICLE_H

// #include <iostream> // Include any necessary standard library headers

// class Particle {
// public:
//     // Constructor
//     Particle(double x, double y, double z, double velocityX, double velocityY, double velocityZ);

//     // Function to update the position of the particle
//     void updatePosition(double deltaTime);

//     // Getter functions for particle properties
//     double getX() const;
//     double getY() const;
//     double getZ() const;

// private:
//     // Member variables to store particle properties
//     double x; // X coordinate
//     double y; // Y coordinate
//     double z; // Z coordinate
//     double velocityX; // Velocity along the X axis
//     double velocityY; // Velocity along the Y axis
//     double velocityZ; // Velocity along the Z axis
// };

// #endif // PARTICLE_H



// #ifndef PARTICLE_H
// #define PARTICLE_H

// #include <glm/glm.hpp>

// class Particle {
// public:
//     Particle(const glm::vec3& position, const glm::vec3& velocity, float lifeTime);
//     ~Particle();

//     void update(float deltaTime);

//     glm::vec3 getPosition() const;
//     void setPosition(const glm::vec3& position);

//     glm::vec3 getVelocity() const;
//     void setVelocity(const glm::vec3& velocity);

//     float getLifeTime() const;
//     void setLifeTime(float lifeTime);

//     bool isAlive() const;

// private:
//     glm::vec3 position;
//     glm::vec3 velocity;
//     float lifeTime;
// };

// #endif // PARTICLE_H


#ifndef PARTICLE_H
#define PARTICLE_H

class Vector3 {
public:
    float x, y, z;

    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

class Particle {
public:
    Particle(const Vector3& position, const Vector3& velocity, float lifeTime);
    ~Particle();

    void update(float deltaTime);

    Vector3 getPosition() const;
    void setPosition(const Vector3& position);

    Vector3 getVelocity() const;
    void setVelocity(const Vector3& velocity);

    float getLifeTime() const;
    void setLifeTime(float lifeTime);

    bool isAlive() const;

private:
    Vector3 position;
    Vector3 velocity;
    float lifeTime;
};

#endif // PARTICLE_H


