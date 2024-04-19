//Vertex
#version 330 core
layout(location = 0) in vec3 a_Pos;
layout(location = 1) in vec3 a_Col;

out vec4 color;

void main() {
    gl_Position = vec4(a_Pos, 1.0);
    color = vec4(a_Col, 1.0);
}

//Fragment
#version 330 core
in vec4 color;

out vec4 FragColor;

void main() {
    FragColor = color;
}
