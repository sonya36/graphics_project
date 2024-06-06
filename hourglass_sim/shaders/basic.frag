#version 330 core

// Input from vertex shader
in vec3 FragColor;

// Output color
out vec4 finalColor;

void main() {
    // Set the final color of the fragment
    finalColor = vec4(FragColor, 1.0);
}
