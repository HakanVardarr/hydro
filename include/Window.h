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
    bool Run() { return !glfwWindowShouldClose(m_glwindow); }

   private:
    GLFWwindow* m_glwindow;
    int m_width, m_height;

    bool init();
};

#endif