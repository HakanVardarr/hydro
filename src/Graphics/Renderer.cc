#include "Graphics/Renderer.h"

void Renderer::Draw(Shader shader, VertexArray vao, IndexBuffer ibo) {
    shader.Use();
    vao.Bind();
    ibo.Bind();
    glDrawElements(GL_TRIANGLES, ibo.Size(), GL_UNSIGNED_INT, 0);
}