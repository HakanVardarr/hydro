#ifndef _WINDOW_H
#define _WINDOW_H

#include "glad/glad.h"
// ------------------
#include "GLFW/glfw3.h"

class Window {
   public:
    Window(const int width, const int height, const char* title);
    ~Window();

    void PollEvents() { glfwPollEvents(); }
    void SwapBuffer() { glfwSwapBuffers(m_glwindow); }
    void Clear() { glClear(GL_COLOR_BUFFER_BIT); }
    bool Run() { return !glfwWindowShouldClose(m_glwindow); }

   private:
    GLFWwindow* m_glwindow;
    int m_width, m_height;

    static void frameBufferSizeCallback(GLFWwindow* window, int width,
                                        int height);

    void loadDefaultIcon();
    void setWidth(int width) { m_width = width; }
    void setHeight(int height) { m_height = height; }
    bool init();
};

#endif