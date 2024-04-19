#include "Core/Window.h"
#include "Graphics/IndexBuffer.h"
#include "Graphics/Shader.h"
#include "Graphics/VertexArray.h"
#include "Graphics/VertexBuffer.h"
#include "spdlog/spdlog.h"

const int WIDTH = 800;
const int HEIGHT = 600;
const char* TITLE = "Hydro";

// clang-format off
const float VERTICES[] = {
    // Position         // Color
     0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,   
    -0.5f,  0.5f, 0.0f, 0.3f, 0.6f, 0.5f,
};

const int INDICES[] = {
    0, 1, 3,
    1, 2, 3
};
// clang-format on

int main() {
    try {
        Hydro::Window window(WIDTH, HEIGHT, TITLE);

        Hydro::VertexBuffer triangleVertexBuffer(VERTICES, sizeof(VERTICES));
        Hydro::VertexArray triangleVertexArray(triangleVertexBuffer, {3, 3});
        Hydro::IndexBuffer triangleIndexBuffer(INDICES, sizeof(INDICES));

        Hydro::Shader triangleShader("/shaders/triangle.glsl");

        while (window.Run()) {
            window.Clear();

            triangleShader.Use();
            triangleVertexArray.Bind();
            triangleIndexBuffer.Bind();
            glDrawElements(GL_TRIANGLES, triangleIndexBuffer.Size(),
                           GL_UNSIGNED_INT, 0);

            window.SwapBuffer();
            window.PollEvents();
        }

    } catch (std::runtime_error& err) {
        spdlog::error(err.what());
        return -1;
    }

    return 0;
}
