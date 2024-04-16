#include <iostream>

#include "Window.h"
#include "spdlog/spdlog.h"

const int WIDTH = 800;
const int HEIGHT = 600;
const char* TITLE = "Hello, world!";

void init();

int main() {
    try {
        Window window(WIDTH, HEIGHT, TITLE);

        while (window.Run()) {
            window.PollEvents();

            window.SwapBuffer();
        }

    } catch (std::runtime_error& err) {
        spdlog::error(err.what());
        return -1;
    }

    return 0;
}
