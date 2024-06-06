// #include <GLFW/glfw3.h>
// #include <cmath>

// void dda_line(int x1, int y1, int x2, int y2) {
//     int dx = x2 - x1;
//     int dy = y2 - y1;
//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
//     float x_increment = dx / (float)steps;
//     float y_increment = dy / (float)steps;

//     float x = x1;
//     float y = y1;

//     glBegin(GL_POINTS);
//     for (int i = 0; i <= steps; i++) {
//         glVertex2i(round(x), round(y));
//         x += x_increment;
//         y += y_increment;
//     }
//     glEnd();
//     glFlush();
// }

// void display() {
//     glClear(GL_COLOR_BUFFER_BIT);
//     glColor3f(1.0, 1.0, 1.0);

//     // Example line coordinates
//     int x1 = -50, y1 = -50;
//     int x2 = 50, y2 = 50;

//     dda_line(x1, y1, x2, y2);
// }

// void init() {
//     glClearColor(0.0, 0.0, 0.0, 0.0);
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
//     glMatrixMode(GL_MODELVIEW);
// }


// int main() {
//     // Initialize GLFW
//     if (!glfwInit()) {
//         return -1;
//     }

//     // Create a windowed mode window and its OpenGL context
//     GLFWwindow* window = glfwCreateWindow(500, 500, "DDA Line Drawing Algorithm using GLFW", NULL, NULL);
//     if (!window) {
//         glfwTerminate();
//         return -1;
//     }

//     // Make the window's context current
//     glfwMakeContextCurrent(window);

//     // Set up the viewport
//     glViewport(0, 0, 500, 500);

//     // Set the display function
//     glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
//         glViewport(0, 0, width, height);
//     });

//     // Set up OpenGL settings
//     init();

//     // Loop until the user closes the window
//     while (!glfwWindowShouldClose(window)) {
//         // Render here
//         display();

//         // Swap front and back buffers
//         glfwSwapBuffers(window);

//         // Poll for and process events
//         glfwPollEvents();
//     }

//     // Terminate GLFW
//     glfwTerminate();
//     return 0;
// }


// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include <iostream>

// // Vertex Shader source code
// const char* vertexShaderSource = R"(
// #version 330 core
// layout(location = 0) in vec3 aPos;
// layout(location = 1) in vec3 aColor;
// out vec3 ourColor;
// void main() {
//     gl_Position = vec4(aPos, 1.0);
//     ourColor = aColor;
// }
// )";

// // Fragment Shader source code
// const char* fragmentShaderSource = R"(
// #version 330 core
// out vec4 FragColor;
// in vec3 ourColor;
// void main() {
//     FragColor = vec4(ourColor, 1.0f);
// }
// )";

// // Callback function to resize the viewport when the window is resized
// void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
//     glViewport(0, 0, width, height);
// }

// // Function to process user input
// void processInput(GLFWwindow *window) {
//     if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//         glfwSetWindowShouldClose(window, true);
// }

// // Function to compile shaders
// unsigned int compileShader(unsigned int type, const char* source) {
//     unsigned int shader = glCreateShader(type);
//     glShaderSource(shader, 1, &source, nullptr);
//     glCompileShader(shader);

//     int success;
//     char infoLog[512];
//     glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
//     if (!success) {
//         glGetShaderInfoLog(shader, 512, nullptr, infoLog);
//         std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
//     }

//     return shader;
// }

// // Function to create a shader program
// unsigned int createShaderProgram(const char* vertexSource, const char* fragmentSource) {
//     unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexSource);
//     unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentSource);

//     unsigned int shaderProgram = glCreateProgram();
//     glAttachShader(shaderProgram, vertexShader);
//     glAttachShader(shaderProgram, fragmentShader);
//     glLinkProgram(shaderProgram);

//     int success;
//     char infoLog[512];
//     glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//     if (!success) {
//         glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
//         std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//     }

//     glDeleteShader(vertexShader);
//     glDeleteShader(fragmentShader);

//     return shaderProgram;
// }

// int main() {
//     // Initialize GLFW
//     if (!glfwInit()) {
//         std::cerr << "Failed to initialize GLFW" << std::endl;
//         return -1;
//     }

//     // Configure GLFW
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

// #ifdef __APPLE__
//     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
// #endif

//     // Create a windowed mode window and its OpenGL context
//     GLFWwindow* window = glfwCreateWindow(800, 600, "Hourglass Simulation", nullptr, nullptr);
//     if (!window) {
//         std::cerr << "Failed to create GLFW window" << std::endl;
//         glfwTerminate();
//         return -1;
//     }

//     // Make the window's context current
//     glfwMakeContextCurrent(window);

//     // Load all OpenGL function pointers
//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//         std::cerr << "Failed to initialize GLAD" << std::endl;
//         return -1;
//     }

//     // Set the viewport
//     glViewport(0, 0, 800, 600);

//     // Register the callback function to adjust the viewport on window resize
//     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

//     // Define the vertices and colors for the hourglass
//     float vertices[] = {
//         // Top pyramid
//         0.0f,  0.5f,  0.0f,  1.0f, 0.0f, 0.0f,  // Vertex 0
//         -0.5f, 0.0f,  0.5f,  1.0f, 0.0f, 0.0f,  // Vertex 1
//         0.5f,  0.0f,  0.5f,  1.0f, 0.0f, 0.0f,  // Vertex 2

//         0.0f,  0.5f,  0.0f,  1.0f, 0.0f, 0.0f,  // Vertex 0
//         0.5f,  0.0f,  0.5f,  1.0f, 0.0f, 0.0f,  // Vertex 2
//         0.5f,  0.0f, -0.5f,  1.0f, 0.0f, 0.0f,  // Vertex 3

//         0.0f,  0.5f,  0.0f,  1.0f, 0.0f, 0.0f,  // Vertex 0
//         0.5f,  0.0f, -0.5f,  1.0f, 0.0f, 0.0f,  // Vertex 3
//         -0.5f, 0.0f, -0.5f,  1.0f, 0.0f, 0.0f,  // Vertex 4

//         0.0f,  0.5f,  0.0f,  1.0f, 0.0f, 0.0f,  // Vertex 0
//         -0.5f, 0.0f, -0.5f,  1.0f, 0.0f, 0.0f,  // Vertex 4
//         -0.5f, 0.0f,  0.5f,  1.0f, 0.0f, 0.0f,  // Vertex 1

//         // Bottom pyramid
//         0.0f, -0.5f,  0.0f,  0.0f, 0.0f, 1.0f,  // Vertex 5
//         -0.5f, 0.0f,  0.5f,  0.0f, 0.0f, 1.0f,  // Vertex 1
//         0.5f,  0.0f,  0.5f,  0.0f, 0.0f, 1.0f,  // Vertex 2

//         0.0f, -0.5f,  0.0f,  0.0f, 0.0f, 1.0f,  // Vertex 5
//         0.5f,  0.0f,  0.5f,  0.0f, 0.0f, 1.0f,  // Vertex 2
//         0.5f,  0.0f, -0.5f,  0.0f, 0.0f, 1.0f,  // Vertex 3

//         0.0f, -0.5f,  0.0f,  0.0f, 0.0f, 1.0f,  // Vertex 5
//         0.5f,  0.0f, -0.5f,  0.0f, 0.0f, 1.0f,  // Vertex 3
//         -0.5f, 0.0f, -0.5f,  0.0f, 0.0f, 1.0f,  // Vertex 4

//                0.0f, -0.5f,  0.0f,  0.0f, 0.0f, 1.0f,  // Vertex 5
//         -0.5f, 0.0f, -0.5f,  0.0f, 0.0f, 1.0f,  // Vertex 4
//         -0.5f, 0.0f,  0.5f,  0.0f, 0.0f, 1.0f,  // Vertex 1
//     };

//     unsigned int VBO, VAO;
//     glGenVertexArrays(1, &VAO);
//     glGenBuffers(1, &VBO);

//     glBindVertexArray(VAO);

//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//     // Position attribute
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);
//     // Color attribute
//     glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//     glEnableVertexAttribArray(1);

//     // Compile and link shaders
//     unsigned int shaderProgram = createShaderProgram(vertexShaderSource, fragmentShaderSource);

//     // Render loop
//     while (!glfwWindowShouldClose(window)) {
//         // Input
//         processInput(window);

//         // Render
//         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);

//         // Draw the hourglass
//         glUseProgram(shaderProgram);
//         glBindVertexArray(VAO);
//         glDrawArrays(GL_TRIANGLES, 0, 24);

//         // Swap buffers and poll IO events (keys pressed/released, mouse moved, etc.)
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     // Cleanup
//     glDeleteVertexArrays(1, &VAO);
//     glDeleteBuffers(1, &VBO);
//     glDeleteProgram(shaderProgram);

//     // Terminate GLFW
//     glfwTerminate();
//     return 0;
// }


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Vertex Shader source code
const char* vertexShaderSource = R"(
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
out vec3 ourColor;
void main() {
    gl_Position = vec4(aPos, 1.0);
    ourColor = aColor;
}
)";

// Fragment Shader source code
const char* fragmentShaderSource = R"(
#version 330 core
out vec4 FragColor;
in vec3 ourColor;
void main() {
    FragColor = vec4(ourColor, 1.0f);
}
)";

// Callback function to resize the viewport when the window is resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// Function to process user input
void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// Function to compile shaders
unsigned int compileShader(unsigned int type, const char* source) {
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    return shader;
}

// Function to create a shader program
unsigned int createShaderProgram(const char* vertexSource, const char* fragmentSource) {
    unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexSource);
    unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentSource);

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Configure GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "Hourglass Simulation", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Set the viewport
    glViewport(0, 0, 800, 600);

    // Register the callback function to adjust the viewport on window resize
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Define the vertices and colors for the hourglass
    float vertices[] = {
        // Top pyramid
        0.0f,  0.5f,  0.0f,  1.0f, 0.0f, 0.0f,  // Top vertex of the top pyramid
        -0.5f, 0.0f,  0.5f,  1.0f, 0.0f, 0.0f,  // Bottom-left vertex
        0.5f,  0.0f,  0.5f,  1.0f, 0.0f, 0.0f,  // Bottom-right vertex

        0.0f,  0.5f,  0.0f,  1.0f, 0.0f, 0.0f,  // Top vertex of the top pyramid
        0.5f,  0.0f,  0.5f,  1.0f, 0.0f, 0.0f,  // Bottom-right vertex
        0.5f,  0.0f, -0.5f,  1.0f, 0.0f, 0.0f,  // Bottom-back vertex

        0.0f,  0.5f,  0.0f,  1.0f, 0.0f, 0.0f,  // Top vertex of the top pyramid
        0.5f,  0.0f, -0.5f,  1.0f, 0.0f, 0.0f,  // Bottom-back vertex
        -0.5f, 0.0f, -0.5f,  1.0f, 0.0f, 0.0f,  // Bottom-back-left vertex

        0.0f,  0.5f,  0.0f,  1.0f, 0.0f, 0.0f,  // Top vertex of the top pyramid
        -0.5f, 0.0f, -0.5f,  1.0f, 0.0f, 0.0f,  // Bottom-back-left vertex
        -0.5f, 0.0f,  0.5f,  1.0f, 0.0f, 0.0f,  // Bottom-left vertex

        // Bottom pyramid
        0.0f, -0.5f,  0.0f,  0.0f, 0.0f, 1.0f,  // Bottom vertex of the bottom pyramid
        -0.5f, 0.0f,  0.5f,  0.0f, 0.0f, 1.0f,  // Top-left vertex
        0.5f,  0.0f,  0.5f,  0.0f, 0.0f, 1.0f,  // Top-right vertex

        0.0f, -0.5f,  0.0f,  0.0f, 0.0f, 1.0f,  // Bottom vertex of the bottom pyramid
        0.5f,  0.0f,  0.5f,  0.0f, 0.0f, 1.0f,  // Top-right vertex
        0.5f,  0.0f, -0.5f,  0.0f, 0.0f, 1.0f,  // Top-back vertex

        0.0f, -0.5f,  0.0f,  0.0f, 0.0f, 1.0f,  // Bottom vertex of the bottom pyramid
        0.5f,  0.0f, -0.5f,  0.0f, 0.0f, 1.0f,  // Top-back vertex
        -0.5f, 0.0f, -0.5f,  0.0f, 0.0f, 1.0f,  // Top-back-left vertex

        0.0f, -0.5f,  0.0f,  0.0f, 0.0f, 1.0f,  // Bottom vertex of the bottom pyramid
        -0.5f, 0.0f, -0.5f,  0.0f, 0.0f, 1.0f,  // Top-back-left vertex
        -0.5f, 0.0f,  0.5f,  0.0f, 0.0f, 1.0f   // Top-left vertex
    };
    






        unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Compile and link shaders
    unsigned int shaderProgram = createShaderProgram(vertexShaderSource, fragmentShaderSource);

    // Render loop
    while (!glfwWindowShouldClose(window)) {
        // Input
        processInput(window);

        // Render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the hourglass
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 24);

        // Swap buffers and poll IO events (keys pressed/released, mouse moved, etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    // Terminate GLFW
    glfwTerminate();
    return 0;
}


