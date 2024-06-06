#version 330 core

// Input attributes
layout(location = 0) in vec3 position;

// Output to fragment shader
out vec3 FragColor;

void main() {
    // Pass the position to the fragment shader
    FragColor = position;
    
    // Set the output position (clip space)
    gl_Position = vec4(position, 1.0);
}
