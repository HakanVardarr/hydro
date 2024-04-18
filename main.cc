#include "Shader.h"
#include "Window.h"
#include "spdlog/spdlog.h"

const int WIDTH = 800;
const int HEIGHT = 600;
const char* TITLE = "Hydro";

int main() {
    try {
        spdlog::set_level(spdlog::level::debug);

        Window window(WIDTH, HEIGHT, TITLE);
        Shader triangleShader("/shaders/triangle.glsl", "Triangle");

        while (window.Run()) {
            window.PollEvents();

            window.Clear();
            window.SwapBuffer();
        }

    } catch (std::runtime_error& err) {
        spdlog::error(err.what());
        return -1;
    }

    return 0;
}
