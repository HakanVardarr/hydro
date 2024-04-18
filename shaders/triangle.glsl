//Vertex
#version 330 core
layout(location = 0) in vec3 a_Pos;
out vec4 o_Col;

void main() {
    gl_Position = vec4(a_Pos, 1.0);
}

//Fragment
#version 330 core
out vec4 FragColor;

void main() {
    FragColor = vec4(1.0);
}
