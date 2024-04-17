#include "Window.h"

#include <sstream>
#include <stdexcept>

#include "spdlog/spdlog.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

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

        glClearColor(0.356, 0.431, 0.882, 1.0);

        glViewport(0, 0, width, height);
        glfwSetFramebufferSizeCallback(m_glwindow, frameBufferSizeCallback);

        loadDefaultIcon();

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

void Window::frameBufferSizeCallback(GLFWwindow* window, int width,
                                     int height) {
    Window* windowInstance =
        static_cast<Window*>(glfwGetWindowUserPointer(window));

    if (windowInstance) {
        windowInstance->setHeight(height);
        windowInstance->setHeight(width);
    }

    glViewport(0, 0, width, height);
}

void Window::loadDefaultIcon() {
    GLFWimage images[1];
    images[0].pixels = stbi_load("../static/default.png", &images[0].width,
                                 &images[0].height, 0, 4);
    glfwSetWindowIcon(m_glwindow, 1, images);
    stbi_image_free(images[0].pixels);
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