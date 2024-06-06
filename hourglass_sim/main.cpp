// #include <iostream>
// #include <GL/glew.h>
// #include "../../dependencies/include/GLFW/glfw3.h"

// Include your header files for other classes (e.g., hourglass.h, particle_system.h)

// Function prototypes
// void initializeGLFW(GLFWwindow** window);
// void initializeGLEW();
// void setupShaders();
// void render(GLFWwindow* window);

// int main() {
//     // Declare window
//     GLFWwindow* window = nullptr;

//     // Initialize GLFW and create window
//     initializeGLFW(&window);

//     // Initialize GLEW
//     initializeGLEW();

//     // Setup shaders
//     setupShaders();

//     // Main rendering loop
//     while (!glfwWindowShouldClose(window)) {
//         // Process input events
//         glfwPollEvents();

//         // Render
//         render(window);

//         // Swap buffers
//         glfwSwapBuffers(window);
//     }

//     // Terminate GLFW
//     glfwTerminate();

//     return 0;
// }

// void initializeGLFW(GLFWwindow** window) {
//     // Initialize GLFW
//     if (!glfwInit()) {
//         std::cerr << "Error: Failed to initialize GLFW" << std::endl;
//         exit(EXIT_FAILURE);
//     }

//     // Set GLFW window hints
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

//     // Create GLFW window
//     // Replace 800 and 600 with your desired window width and height
//     *window = glfwCreateWindow(800, 600, "Hourglass Simulation", NULL, NULL);
//     if (!*window) {
//         std::cerr << "Error: Failed to create GLFW window" << std::endl;
//         glfwTerminate();
//         exit(EXIT_FAILURE);
//     }

//     // Make the window's context current
//     glfwMakeContextCurrent(*window);
// }

// void initializeGLEW() {
//     // Initialize GLEW
//     GLenum err = glewInit();
//     if (err != GLEW_OK) {
//         std::cerr << "Error: Failed to initialize GLEW: " << glewGetErrorString(err) << std::endl;
//         exit(EXIT_FAILURE);
//     }
// }

// void setupShaders() {
//     // Implement shader setup code here
// }

// void render(GLFWwindow* window) {
//     // Implement rendering code here
// }

#include <iostream>
#include "dependencies/include/GLFW/glfw3.h"
// Replace with appropriate OpenGL header for macOS (might be gl.h)
#include "include/hourglass.h"
#include "include/particle.h"  // Assuming particle.h is relevant for your simulation

// Function prototypes
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// Settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    // Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hourglass Simulation", NULL, NULL);
    if (window == NULL) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // **No GLAD for macOS (assuming system-provided OpenGL):**

    // Create the hourglass
    Hourglass hourglass;

    // Game loop
    while (!glfwWindowShouldClose(window)) {
        // Input handling
        processInput(window);

        // Rendering
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Render the hourglass
        hourglass.render(); // Implement rendering logic using OpenGL functions

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();
    return 0;
}

// Function to handle window resizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// Function to process input
void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

