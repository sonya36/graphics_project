// #include "../include/hourglass.h"
// #include <glad/glad.h>
// #include <iostream> // Include any necessary standard library headers

// Hourglass::Hourglass() {
//     // Constructor implementation
//     height = 10; // Example initialization
//     width = 5;   // Example initialization
//     flipped = false; // Example initialization
//     filledWithSand = false; // Example initialization
// }

// void Hourglass::render() const {
//     // Rendering logic for the hourglass
//     std::cout << "Rendering the hourglass..." << std::endl;
// }

// void Hourglass::flip() {
//     // Logic to flip the hourglass
//     flipped = !flipped;
//     std::cout << "The hourglass is now " << (flipped ? "flipped" : "unflipped") << std::endl;
// }

// void Hourglass::fillWithSand(int amount) {
//     // Logic to fill the hourglass with sand
//     // Example implementation: increase sand level by amount
//     // This is just a placeholder implementation
//     std::cout << "Filling the hourglass with " << amount << " units of sand..." << std::endl;
//     filledWithSand = true;
// }

// void Hourglass::empty() {
//     // Logic to empty the hourglass
//     filledWithSand = false;
//     std::cout << "Emptying the hourglass..." << std::endl;
// }






// // Example shader source code
// const char* vertexShaderSource = R"(
//     #version 330 core
//     layout (location = 0) in vec3 aPos;
//     void main() {
//         gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
//     }
// )";

// const char* fragmentShaderSource = R"(
//     #version 330 core
//     out vec4 FragColor;
//     void main() {
//         FragColor = vec4(1.0, 1.0, 1.0, 1.0);
//     }
// )";

// Hourglass::Hourglass() : flipped(false), filledWithSand(false) {
//     // Initialize hourglass properties and OpenGL resources
//     createHourglassGeometry();

//     // Compile shaders and link shader program
//     GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
//     GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
//     shaderProgram = linkShaderProgram(vertexShader, fragmentShader);

//     // Cleanup shader objects
//     glDeleteShader(vertexShader);
//     glDeleteShader(fragmentShader);
// }

// Hourglass::~Hourglass() {
//     // Cleanup OpenGL resources
//     glDeleteVertexArrays(1, &vao);
//     glDeleteBuffers(1, &vbo);
//     glDeleteProgram(shaderProgram);
// }

// void Hourglass::render() const {
//     // Use shader program
//     glUseProgram(shaderProgram);

//     // Draw hourglass
//     glBindVertexArray(vao);
//     glDrawArrays(GL_LINES, 0, 16);
//     glBindVertexArray(0);
// }

// void Hourglass::flip() {
//     // Function to flip the hourglass
//     flipped = !flipped;
//     // Adjust hourglass geometry or orientation when flipped
// }

// void Hourglass::fillWithSand(float amount) {
//     // Function to fill the hourglass with sand
//     filledWithSand = true;
// }

// void Hourglass::empty() {
//     // Function to empty the hourglass
//     filledWithSand = false;
// }

// GLuint Hourglass::compileShader(GLenum type, const char* source) {
//     GLuint shader = glCreateShader(type);
//     glShaderSource(shader, 1, &source, NULL);
//     glCompileShader(shader);

//     GLint success;
//     glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
//     if (!success) {
//         char infoLog[512];
//         glGetShaderInfoLog(shader, 512, NULL, infoLog);
//         std::cerr << "Shader compilation error: " << infoLog << std::endl;
//         // Handle shader compilation error
//     }

//     return shader;
// }

// GLuint Hourglass::linkShaderProgram(GLuint vertexShader, GLuint fragmentShader) {
//     GLuint program = glCreateProgram();
//     glAttachShader(program, vertexShader);
//     glAttachShader(program, fragmentShader);
//     glLinkProgram(program);

//     GLint success;
//     glGetProgramiv(program, GL_LINK_STATUS, &success);
//     if (!success) {
//         char infoLog[512];
//         glGetProgramInfoLog(program, 512, NULL, infoLog);
//         std::cerr << "Shader program linking error: " << infoLog << std::endl;
//         // Handle shader program linking error
//     }

//     return program;
// }

// void Hourglass::createHourglassGeometry() {
//     GLfloat hourglassVertices[] = {
//         // Top
//         -0.5f, 0.5f, 0.0f,
//         0.5f, 0.5f, 0.0f,

//         // Bottom
//         -0.5f, -0.5f, 0.0f,
//         0.5f, -0.5f, 0.0f,

//         // Left
//         -0.5f, 0.5f, 0.0f,
//         -0.5f, -0.5f, 0.0f,

//         // Right
//         0.5f, 0.5f, 0.0f,
//         0.5f, -0.5f, 0.0f,

//         // Middle divider
//         -0.25f, 0.25f, 0.0f,
//         0.25f, 0.25f, 0.0f,
//         -0.25f, -0.25f, 0.0f,
//         0.25f, -0.25f, 0.0f
//     };

//     // Generate VAO and VBO
//     glGenVertexArrays(1, &vao);
//     glGenBuffers(1, &vbo);

//     // Bind VAO and VBO
//     glBindVertexArray(vao);
//     glBindBuffer(GL_ARRAY_BUFFER, vbo);

//     // Copy vertex data to VBO
//     glBufferData(GL_ARRAY_BUFFER, sizeof(hourglassVertices), hourglassVertices, GL_STATIC_DRAW);

//     // Set vertex attribute pointers
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
//     glEnableVertexAttribArray(0);

//     // Unbind VAO and VBO
//     glBindBuffer(GL_ARRAY_BUFFER, 0);
//     glBindVertexArray(0);
// }

#include "../include/hourglass.h"
#include <iostream>

const char* vertexShaderSource = R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    void main() {
        gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    }
)";

const char* fragmentShaderSource = R"(
    #version 330 core
    out vec4 FragColor;
    void main() {
        FragColor = vec4(1.0, 1.0, 1.0, 1.0);
    }
)";


Hourglass::Hourglass() : flipped(false), filledWithSand(false) {
    // Initialize hourglass properties and OpenGL resources
    createHourglassGeometry();

    // Compile shaders and link shader program
    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
    shaderProgram = linkShaderProgram(vertexShader, fragmentShader);

    // Cleanup shader objects
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Hourglass::~Hourglass() {
    // Cleanup OpenGL resources
    glDeleteBuffers(1, &vbo);
    glDeleteProgram(shaderProgram);
}

void Hourglass::render() const {
    // Use shader program
    glUseProgram(shaderProgram);

    // Set vertex attribute pointers
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);

    // Draw hourglass
    glDrawArrays(GL_LINES, 0, 16);
}

void Hourglass::flip() {
    // Function to flip the hourglass
    flipped = !flipped;
    // Adjust hourglass geometry or orientation when flipped
}

void Hourglass::fillWithSand(float amount) {
    // Function to fill the hourglass with sand
    filledWithSand = true;
}

void Hourglass::empty() {
    // Function to empty the hourglass
    filledWithSand = false;
}

GLuint Hourglass::compileShader(GLenum type, const char* source) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << "Shader compilation error: " << infoLog << std::endl;
        // Handle shader compilation error
    }

    return shader;
}

GLuint Hourglass::linkShaderProgram(GLuint vertexShader, GLuint fragmentShader) {
    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cerr << "Shader program linking error: " << infoLog << std::endl;
        // Handle shader program linking error
    }

    return program;
}

void Hourglass::createHourglassGeometry() {
    GLfloat hourglassVertices[] = {
        // Top
        -0.5f, 0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,

        // Bottom
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,

        // Left
        -0.5f, 0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,

        // Right
        0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,

        // Middle divider
        -0.25f, 0.25f, 0.0f,
        0.25f, 0.25f, 0.0f,
        -0.25f, -0.25f, 0.0f,
        0.25f, -0.25f, 0.0f
    };

    // Generate VBO
    glGenBuffers(1, &vbo);

    // Bind VBO
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // Copy vertex data to VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(hourglassVertices), hourglassVertices, GL_STATIC_DRAW);
}




