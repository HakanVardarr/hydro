//Vertex
#version 330

in vec3 iPos;

void main() {
    gl_Position = vec4(iPos, 1.0);
}

//Fragment
#version 330

out vec4 FragColor;

void main() {
    FragColor = vec4(1.0);
}
