#include "Window.h"

#include <sstream>
#include <stdexcept>

#include "spdlog/spdlog.h"

Window::Window(const int width, const int height, const char* title)
    : m_width(width), m_height(height) {
    if (Window::init()) {
        m_glwindow = glfwCreateWindow(width, height, title, NULL, NULL);
        if (m_glwindow == NULL) {
            throw std::runtime_error("[WINDOW]: Failed to create glfw window.");
        }

        glfwMakeContextCurrent(m_glwindow);

        if (!gladLoadGL()) {
            throw std::runtime_error("[WINDOW]: Failed to load GL.");
        }

        glViewport(0, 0, width, height);

        std::stringstream vendor, renderer;
        vendor << "Vendor: " << glGetString(GL_VENDOR);
        renderer << "Renderer: " << glGetString(GL_RENDERER);

        spdlog::info(vendor.str());
        spdlog::info(renderer.str());
    }
}

Window::~Window() {
    glfwDestroyWindow(m_glwindow);
    glfwTerminate();
    spdlog::info("Window successfuly closed.");
}

bool Window::init() {
    if (!glfwInit()) {
        return false;
    }
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    return true;
}