#include <iostream>

#include "glad/glad.h"
//
#include "GLFW/glfw3.h"

const int WIDTH = 800;
const int HEIGHT = 600;
const char* TITLE = "Hello, world!";

void init();

int main() {
    init();
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);

    if (window == NULL) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGL()) {
        std::cerr << "Failed to load GL" << std::endl;
        return -1;
    }

    glViewport(0, 0, WIDTH, HEIGHT);

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

void init() {
    glfwInit();
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}