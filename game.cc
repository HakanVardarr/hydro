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
     //Position      //Color
     0.0, 0.5,  0.0, 1.0, 0.0, 0.0,
    -0.5, -0.5, 0.0, 0.0, 1.0, 0.0,
     0.5, -0.5, 0.0, 0.0, 0.0, 1.0,
};

const int INDICES[] = {
    0, 1, 2,
};
// clang-format on

int main() {
    try {
        Window window(WIDTH, HEIGHT, TITLE);

        VertexBuffer triangleVertexBuffer(VERTICES, sizeof(VERTICES));
        VertexArray triangleVertexArray(triangleVertexBuffer, {3, 3});
        IndexBuffer triangleIndexBuffer(INDICES, sizeof(INDICES));

        Shader triangleShader("/shaders/default.glsl");

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
