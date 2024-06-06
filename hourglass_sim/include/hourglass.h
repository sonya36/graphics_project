// #ifndef HOURGLASS_H
// #define HOURGLASS_H

// #include <iostream>

// class Hourglass {
// public:
//     Hourglass(); // Constructor
//     void render() const; // Function to render the hourglass
//     void flip(); // Function to flip the hourglass
//     void fillWithSand(int amount); // Function to fill the hourglass with sand
//     void empty(); // Function to empty the hourglass
//     // Other member functions...

// private:
//     int height; // Height of the hourglass
//     int width; // Width of the hourglass
//     bool flipped; // Flag indicating if the hourglass is flipped
//     bool filledWithSand; // Flag indicating if the hourglass is filled with sand
//     // Other member variables...
// };

// #endif // HOURGLASS_H
#ifndef HOURGLASS_H
#define HOURGLASS_H
#include "../dependencies/include/glad/glad.h"

class Hourglass {
public:
    Hourglass(); // Constructor
    ~Hourglass(); // Destructor
    void render() const; // Function to render the hourglass
    void flip(); // Function to flip the hourglass
    void fillWithSand(float amount); // Function to fill the hourglass with sand
    void empty(); // Function to empty the hourglass

private:
    GLuint vao; // Vertex Array Object
    GLuint vbo; // Vertex Buffer Object
    GLuint shaderProgram; // Shader program ID
    bool flipped; // Flag indicating if the hourglass is flipped
    bool filledWithSand; // Flag indicating if the hourglass is filled with sand

    GLuint compileShader(GLenum type, const char* source); // Function to compile shader
    GLuint linkShaderProgram(GLuint vertexShader, GLuint fragmentShader); // Function to link shader program
    void createHourglassGeometry(); // Function to create hourglass geometry
};

#endif // HOURGLASS_H






